#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    unsigned char *mem;
    size_t i;
    size_t total_size;

    total_size = count * size;
    mem = malloc(total_size);
    if (!mem)
        return NULL;
    i = 0;
    while (i < total_size)
    {
        mem[i] = 0;
        i++;
    }
    return (void *)mem;
}