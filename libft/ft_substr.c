#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *substr;

    substr = malloc(len);
    if (!substr)
        return NULL;
    i = 0;
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    return substr;
}