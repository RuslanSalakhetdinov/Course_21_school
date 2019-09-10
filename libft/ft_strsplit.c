#include "libft.h"

char        **ft_strsplit(char const *s, char c)
{
    char    **arr;
    int     count;
    int     mark;

    mark = 0;
    count = 0;
    while (*s)
    {
        if (*s != c && mark != 1)
        {
            count++;
            mark++;
        }
        if (*s == c && mark == 1)
            mark--;
        s++;
    }
    arr = (char*)malloc(sizeof(*arr) * 
}
