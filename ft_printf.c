#include "libftprintf.h"

static int valid_specifier(char c)
{
    if (!(c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X' || c == '%'))
        return (0);
    return (1);
}

// void call_relative_ft(int i, int count, char *format)
// {
// }

// __attribute__((format(printf, 1, 2)))
int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i, count;

    if (!format)
        return (0);
    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%' && !valid_specifier(format[i + 1]))
        {
            ft_putstr_fd("Invalid specifier\n", 1);
            return (0);
        }
        else if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
                ft_putchar_fd(va_arg(args, int), 1);
            else if (format[i] == 's')
                ft_putstr_fd(va_arg(args, char *), 1);
            else if (format[i] == 'p')
                ft_print_pointer_fd(va_arg(args, void *), 1);
            else if (format[i] == 'i' || format[i] == 'd')
                ft_putnbr_fd(va_arg(args, int), 1);
            else if (format[i] == 'u')
                ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1); // 2147483648 returns error in original but not in this
            else if (format[i] == 'x')
                ft_puthex_fd(va_arg(args, unsigned int), 1, "0123456789abcdef");
            else if (format[i] == 'X')
                ft_puthex_fd(va_arg(args, unsigned int), 1, "0123456789ABCDEF");
            else if (format[i] == '%')
                ft_putchar_fd('%', 1);
            count++;
        }
        else
        {
            ft_putchar_fd(format[i], 1);
            count++;
        }
        i++;
    }
    return count;
}

// The case where ft_printf is used to print the type we don't support in this func ????
// printf("%\n") ????
// Check types for each function