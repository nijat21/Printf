#include "ft_printf.h"

static int valid_specifier(char c)
{
    if (!(c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X' || c == '%'))
        return (0);
    return (1);
}

int call_relative_ft(char c, va_list args)
{
    if (c == 'c')
        return print_char(va_arg(args, int));
    else if (c == 's')
        return print_string(va_arg(args, char *));
    else if (c == 'p')
        return print_pointer(va_arg(args, void *));
    else if (c == 'i' || c == 'd')
        return print_number(va_arg(args, int));
    else if (c == 'u')
        return print_unsigned_number(va_arg(args, unsigned int)); // 2147483648 returns error in original but not in this
    else if (c == 'x')
        return print_hex(va_arg(args, unsigned int), "0123456789abcdef");
    else if (c == 'X')
        return print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
    else if (c == '%')
        return print_char('%');
    return (0);
}

static int iterate_format(const char *format, int count, int *i, va_list args)
{
    if (format[*i] == '%')
    {
        (*i)++;
        if (!valid_specifier(format[*i]))
            return (0);
        else
            count += call_relative_ft(format[*i], args);
    }
    else
    {
        print_char(format[*i]);
        count++;
    }
    return count;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i;
    int count;

    if (!format)
        return (0);
    i = 0;
    count = 0;
    while (format[i])
    {
        count = iterate_format(format, count, &i, args);
        i++;
    }
    va_end(args);
    return count;
}