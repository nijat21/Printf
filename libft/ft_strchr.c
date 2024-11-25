#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *str;

    str = (char *)s;
    while (*str)
    {
        if (c == *str)
            return str;
        str++;
    }
    if (c == '\0')
        return str;
    return NULL;
}