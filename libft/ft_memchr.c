#include <string.h>

void                    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *buf;

    buf = (const unsigned char)s;
    while (--n)
        if (*buf++ == (unsigned char)c)
            return (*buf);
    return (NULL);
}
