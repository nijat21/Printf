#include "../ft_printf.h"

int main(void)
{
    printf("Mine\n");
    printf("%i\n", ft_printf("%s", ""));
    printf("%i\n", ft_printf(" %s", ""));
    printf("%i\n", ft_printf("%s ", ""));
    printf("%i\n", ft_printf(" %s ", ""));
    printf("%i\n", ft_printf(" %s ", "-"));
    printf("%i\n", ft_printf(" %s %s ", "", "-"));
    printf("%i\n", ft_printf(" %s %s ", " - ", ""));
    printf("%i\n", ft_printf(" %s %s %s %s %s", " - ", "", "4", "", "s2"));
    printf("%i\n", ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
    printf("%i\n", ft_printf(" NULL %s NULL ", (char *)NULL));

    printf("\n");
    printf("Original\n");
    printf("%i\n", printf("%s", ""));
    printf("%i\n", printf(" %s", ""));
    printf("%i\n", printf("%s ", ""));
    printf("%i\n", printf(" %s ", ""));
    printf("%i\n", printf(" %s ", "-"));
    printf("%i\n", printf(" %s %s ", "", "-"));
    printf("%i\n", printf(" %s %s ", " - ", ""));
    printf("%i\n", printf(" %s %s %s %s %s", " - ", "", "4", "", "s2"));
    printf("%i\n", printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
    printf("%i\n", printf(" NULL %s NULL ", (char *)NULL));

    return (0);
}