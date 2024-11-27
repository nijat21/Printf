#include "libftprintf.h"

static int valid_specifier(char c)
{
    if (!(c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X' || c == '%'))
        return (0);
    return (1);
}

int call_relative_ft(char c, va_list args)
{
    if (c == 'c')
        ft_putchar_fd(va_arg(args, int), 1);
    else if (c == 's')
        ft_putstr_fd(va_arg(args, char *), 1);
    else if (c == 'p')
        ft_print_pointer_fd(va_arg(args, void *), 1);
    else if (c == 'i' || c == 'd')
        ft_putnbr_fd(va_arg(args, int), 1);
    else if (c == 'u')
        ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1); // 2147483648 returns error in original but not in this
    else if (c == 'x')
        ft_puthex_fd(va_arg(args, unsigned int), 1, "0123456789abcdef");
    else if (c == 'X')
        ft_puthex_fd(va_arg(args, unsigned int), 1, "0123456789ABCDEF");
    else if (c == '%')
        ft_putchar_fd('%', 1);
    return (1);
}

// int iterate_format(const char *format, int i)
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
        if (format[i] == '%')
        {
            i++;
            if (!valid_specifier(format[i]))
                return (0);
            else
                count += call_relative_ft(format[i], args);
        }
        else
        {
            ft_putchar_fd(format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return count;
}

// The case where ft_printf is used to print the type we don't support in this func ????
// printf("%\n") ????
// Check types for each function