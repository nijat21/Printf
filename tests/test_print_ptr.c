#include "../ft_printf.h"
#include <limits.h>

int main(void)
{
    printf("Mine\n");
    printf("%i\n", ft_printf(" %p ", -1));
    printf("%i\n", ft_printf(" %p ", 1));
    printf("%i\n", ft_printf(" %p ", 15));
    printf("%i\n", ft_printf(" %p ", 16));
    printf("%i\n", ft_printf(" %p ", 17));
    printf("%i\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
    printf("%i\n", ft_printf(" %p %p ", INT_MIN, INT_MAX));
    printf("%i\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
    printf("%i\n", ft_printf(" %p %p ", 0, 0));

    printf("\n");
    printf("Original\n");
    printf("%i\n", printf(" %p ", (void *)-1));
    printf("%i\n", printf(" %p ", (void *)1));
    printf("%i\n", printf(" %p ", (void *)15));
    printf("%i\n", printf(" %p ", (void *)16));
    printf("%i\n", printf(" %p ", (void *)17));
    printf("%i\n", printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX));
    printf("%i\n", printf(" %p %p ", (void *)INT_MIN, (void *)INT_MAX));
    printf("%i\n", printf(" %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX));
    printf("%i\n", printf(" %p %p ", (void *)0, (void *)0));
    return (0);
}