#include <string.h>

size_t  ft_strlen(const char *s)
{
    size_t num;

    num = 0;
    while (*s)
        {
            num++;
            s++;
        }
    return (num);
}
