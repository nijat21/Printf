#include "ft_printf.h"

int print_string(char *str)
{
    if (!str)
        str = "(null)";
    if (*str == '\0')
        return (0);
    ft_putstr_fd(str, 1);
    return ft_strlen(str);
}