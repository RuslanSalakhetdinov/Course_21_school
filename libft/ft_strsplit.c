#include "libft.h"

static void ft_count_words(int *count, char *c)
{
    int     mark;

    mark = 0;
    while (*s)
    {
        if (*s != (*c) && mark != 1)
        {
            (*count)++;
            mark++;
        }
        if (*s == (*c) && mark == 1)
            mark--;
        s++;
    }

}

static char *ft_len_word(int *len, char *str)
{

}

char        **ft_strsplit(char const *s, char c)
{
    char    **arr;
    int     count;
    int     i;
    int     len;

    count = 0;
    ft_count_words(&count, &c);
    arr = (char*)malloc(sizeof(*arr) * (count + 1));
    i = -1;
    while (++i < count)
    {
        len = 0;
        buf = ft_len_word(&len, buf)
    }

}

