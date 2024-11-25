#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    size_t i;
    size_t str_len;
    char *str;

    str = (char *)s;
    str_len = ft_strlen(str);
    i = str_len + 1;
    while (i > 0)
    {
        i--;
        if ((unsigned char)c == (unsigned char)str[i])
            return &str[i];
    }
    return NULL;
}