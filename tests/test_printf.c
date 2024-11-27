#include "../libftprintf.h"

int main(void)
{
    /*     ft_printf("Char: %c\n", 'c');
        ft_printf("String: %s\n", "mf");
        ft_printf("Pointer: %p\n", "mf");
        ft_printf("Int: %i\n", (int)-2147483648);
        printf("Int: %i\n", (int)-2147483648);
        ft_printf("Decimal: %d\n", (int)-2147483648);
        printf("Decimal: %d\n", (int)-2147483648);
        ft_printf("Unsigned int: %u\n", (int)2147483648); // 2147483648 returns error in original but not in this
        printf("Unsigned int: %u\n", (int)2147483648);    // 2147483648 returns error in original but not in this
        ft_printf("Number in hex lowercase and uppercase: %x %X\n", -256, -256); */
    // ft_printf("invalid followed by string: %q %s\n", "some", "1, 2");
    // printf("invalid followed by string: %q %s\n", "some", "1, 2");
    // printf(": %\n", "some", "1, 2");
    // printf(": %\n");
    // printf(": % \n");
    // ft_printf(": %\n", "some", "1, 2");
    // ft_printf(": %\n");
    // ft_printf(": % \n");
    // printf("int: %i\n", 1, 2);
    // printf("%i\n", ft_printf("Ints: %i\n", 1));
    printf("%i\n", ft_printf("Ints: %i %i\n", 1, 2));
    printf("%i\n", printf("Ints: %i %i\n", 1, 2));
    // printf("%i\n", ft_printf("Percentage: %%\n"));
    // printf("%i\n", printf("Percentage: %%\n"));

    return (0);
}