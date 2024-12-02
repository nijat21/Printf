
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

int ft_printf(const char *format, ...);

int print_string(char *str);
int print_char(char c);
int print_pointer(void *ptr);
int print_number(int num);
int print_unsigned_number(unsigned int n);
int print_hex(unsigned int n, char *base);

void bonus1();

#endif