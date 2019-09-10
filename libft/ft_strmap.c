#include <stdlib.h>

char        *ft_strmap(char const *s, char (*f) (char))
{
    char    *buf;
    int     i;

    buf = (char*)malloc(sizeof(*buf) * ft_strlen((char*)s));
    if (!buf)
        return (NULL);
    i = 0;
    while (s[i])
        buf[i] = (*f)(s[i++]);
    return (buf);
}
