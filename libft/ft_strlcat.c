size_t  strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;

    i = 0;
    while (dst[i] != '\0')
        i++;
    if (i == size)
        return (size);
    j = 0;
    size -= i;
    while (src[j] != '\0' && size > 1)
    {
        dst[i + j] = src[j];
        j++;
        size--;
    }
    dst[i + j] = '\0';
    return (i + j);
}
