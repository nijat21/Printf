#include "libft.h"

static size_t count_words(char const *s, char c)
{
    size_t in_word;
    size_t count;

    in_word = 0;
    count = 0;
    while (*s)
    {
        if (*s != c)
        {
            if (!in_word)
            {
                count++;
                in_word = 1;
            }
        }
        else
            in_word = 0;
        s++;
    }
    return count;
}

char **arc_split(char const *s, char c)
{
    char **res;
    char const *start;
    size_t len;
    size_t i;
    size_t j;

    res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!res)
        return NULL;
    i = 0;
    while (*s)
    {
        j = 0;
        if (*s != c)
        {
            start = s;
            len = 0;
            while (*s && *s != c)
            {
                len++;
                s++;
            }
            res[i] = (char *)malloc((len + 1) * sizeof(char));
            if (!res[i])
            {
                while (res[--i])
                    free(res[i]);
                free(res);
                return NULL;
            }
            while (start[j] && j < len)
            {
                res[i][j] = start[j];
                j++;
            }
            res[i][j] = '\0';
            i++;
        }
        else
            s++;
    }
    res[i] = NULL;
    return res;
}

// Other version

static char *allocate_assign(char ***res, char const *start, size_t len, size_t i)
{
    size_t j;

    j = 0;
    (*res)[i] = (char *)malloc((len + 1) * sizeof(char));
    if (!(*res)[i])
    {
        while ((*res)[--i])
            free((*res)[i]);
        free((*res));
        return NULL;
    }
    while (start[j] && j < len)
    {
        (*res)[i][j] = start[j];
        j++;
    }
    (*res)[i][j] = '\0';
    return (*res)[i];
}

char **copy_split(char const *s, char c)
{
    char const *start;
    char **res;
    size_t len;
    size_t i;

    res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!res)
        return NULL;
    i = 0;
    while (*s)
    {
        if (*s != c)
        {
            start = s;
            len = 0;
            while (*s && *s != c)
            {
                len++;
                s++;
            }
            res[i] = allocate_assign(&res, start, len, i);
            i++;
        }
        else
            s++;
    }
    res[i] = NULL;
    return res;
}