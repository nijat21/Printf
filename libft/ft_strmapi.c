#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t len;
    size_t i;
    char *res;

    if (!s)
        return NULL;
    len = ft_strlen(s);
    res = malloc((len + 1) * sizeof(char));
    if (!res)
        return NULL;
    i = 0;
    while (s[i])
    {
        res[i] = f(i, s[i]);
        i++;
    }
    res[i] = '\0';
    return res;
}