#include "ft_printf.h"

static void ft_hex_base16(uintptr_t num, int fd, int *count, char *base)
{
    if (num >= 16)
        ft_hex_base16(num / 16, fd, count, base);
    write(fd, &base[num % 16], 1);
    (*count)++;
}

static int ft_print_pointer_fd(void *ptr, int fd)
{
    uintptr_t address;
    int count;

    address = (uintptr_t)ptr;
    write(fd, "0x", 2);
    count = 2;
    if (address == 0)
    {
        write(fd, "0", 1);
        count++;
    }
    else
        ft_hex_base16(address, fd, &count, "0123456789abcdef");
    return count;
}

int print_pointer(void *ptr)
{
    return ft_print_pointer_fd(ptr, 1);
    ;
}