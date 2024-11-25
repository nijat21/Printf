#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    char *str;
    size_t i;

    str = (char *)s;
    if (n > 0)
    {
        i = 0;
        while (i < n)
        {
            str[i] = 0;
            i++;
        }
    }
}