#include "libftprintf.h"

void ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
    char temp;

    if (!n || fd < 0)
        return;
    if (n >= 10)
        ft_putnbr_unsigned_fd(n / 10, fd);
    temp = n % 10 + '0';
    write(fd, &temp, 1);
}