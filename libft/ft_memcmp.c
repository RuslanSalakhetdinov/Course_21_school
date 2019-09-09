#include <string.h>

int                     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *b1;
    const unsigned char *b2;

    b1 = (const unsigned char)s1;
    b2 = (const unsigned char)s2;

    while (--n)
    {
        if (*b1 != *b2)
            return ((int)(*b1) - (int)(*b2));
        b1++;
        b2++;
    }
    return (0);
}
