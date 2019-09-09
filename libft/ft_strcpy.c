#include <string.h>

char    *ft_strcpy(char *dest, const char *src)
{
    int i;

    i = -1;
    while (src[++i])
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
