#include "libft.h"

char        *ft_strjoin(char const *s1, char const *s2)
{
    char    *buf;
    int     len1;
    int     len2

    len1 = ft_strlen((char*)s1);
    len2 = ft_strlen((char*)s2);
    buf = (char*)malloc(sizeof(*buf) * (len1 + len2 + 1));
    if (!buf)
        return (NULL);
    buf[len1 + len2 + 1] = '\0';
    while (--len2 >= 0)
        buf[len1 + len2] = s2[len2];
    while (--len1 >= 0)
        buf[len1] = s1[len1];
    return (buf);
}
