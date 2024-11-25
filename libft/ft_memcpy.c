#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;
    char *source;
    char *destination;

    source = (char *)src;
    destination = (char *)dst;
    i = 0;
    while (i < n)
    {
        destination[i] = source[i];
        i++;
    }
    return dst;
}