#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    char *destination;
    const char *source;
    size_t i;

    if (len == 0 || dst == src)
        return dst;
    destination = (char *)dst;
    source = (const char *)src;
    if (src < dst)
    {
        i = len;
        while (i > 0)
        {
            i--;
            destination[i] = source[i];
        }
    }
    else
    {
        i = 0;
        while (i < len)
        {
            destination[i] = source[i];
            i++;
        }
    }
    return dst;
}