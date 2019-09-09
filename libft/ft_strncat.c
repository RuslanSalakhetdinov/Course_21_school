#include <string.h>

char    *ft_strncat(char *dest, const char *src, size_t n)
{
    int i;
    int j;

    i = 0;
    while (dest[i])
        i++;
    j = 0;
    while (src[j] && n)
    {
        dest[i + j] = src[j];
        j++;
        n--;
    }
    if (!n)
        dest[i + j] = '\0';
    return (dest);
}
