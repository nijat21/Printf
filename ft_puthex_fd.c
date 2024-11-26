#include "libftprintf.h"

void ft_puthex_fd(unsigned int num, int fd, char *base)
{
    if (num >= 16)
        ft_puthex_fd(num / 16, fd, base);
    write(fd, &base[num % 16], 1);
}