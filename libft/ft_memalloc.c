#include <strlib.h>

void                *ft_memalloc(size_t size)
{
    unsigned char   *area;

    area = (unsigned char*)malloc(sizeof(*area) * size);
    if(!area)
        return (NULL);
    while (size)
        area[--size] = 0;
    return (area);
}
