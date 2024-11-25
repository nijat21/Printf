#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    if (!c || fd < 0)
        return;
    write(fd, &c, 1);
}