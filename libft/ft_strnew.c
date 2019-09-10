#include <stdlib.h>

char                *ft_strnew(size_t size)
{
    unsigned char   *str;
    
    str = (unsigned char*)malloc(sizeof(*str) * (size + 1));
    if (!str)
        return (NULL);
    size += 2;
    while (--size)
        str[size] = '\0';
    return (str);
}
