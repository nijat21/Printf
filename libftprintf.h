
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

// __attribute__((format(printf, 1, 2)))
int ft_printf(const char *format, ...);
void ft_print_pointer_fd(void *ptr, int fd);
void ft_putnbr_unsigned_fd(unsigned int n, int fd);
void ft_puthex_fd(unsigned int num, int fd, char *base);

#endif