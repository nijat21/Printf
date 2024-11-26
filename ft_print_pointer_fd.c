#include "libftprintf.h"

static void ft_hex_base16(uintptr_t num, int fd, char *base)
{
    if (num >= 16)
        ft_hex_base16(num / 16, fd, base);
    write(fd, &base[num % 16], 1);
}

void ft_print_pointer_fd(void *ptr, int fd)
{
    uintptr_t address;

    address = (uintptr_t)ptr;
    write(fd, "0x", 2);
    if (address == 0)
        write(fd, "0", 1);
    else
        ft_hex_base16(address, fd, "0123456789abcdef");
}