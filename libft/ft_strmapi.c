#include <stdlib.h>

char                *ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
    char            *buf;
    unsigned int    i;

    buf = (char*)malloc(sizeof(*buf) * ft_strlen((char*)s));
    if (!buf)
        return (NULL);
    i = 0;
    while (s[i])
        buf[i] = (*f)(i, s[i++]);
    return (buf);
}
