#include "libft.h"

char    *ft_strtrim(char const *s)
{
    char *buf;
    char *end;

    buf = (char*)s;
    while (*buf == ' ' || *buf == '\t' || *buf == '\n')
        buf++;
    end = buf;
    while (*end)
        end++;
    while (*end == ' ' || *end == '\t' || *end == '\n')
        *end-- = '\0';
    return (ft_strdup(buf));
}
