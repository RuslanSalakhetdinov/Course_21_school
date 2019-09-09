#include <string.h>
#include <stdlib.h>

char            *srtdup(const char *s)
{
    const char  *buf;
    int         len;

    len = ft_strlen(s);
    buf = (const char*)malloc(sizeof(*buf) * (len + 1));
    if (!buf)
    {
        //errno???
        return (NULL);
    }
    len = -1;
    while (++len < ft_strlen(s))
        buf[len] = s[len];
    buf[len] = '\0';
    return (buf);
}
