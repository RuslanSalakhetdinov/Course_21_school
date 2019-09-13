#include "libft.h"

char	*ft_strrchr(const char *s, int *c)
{
	char *buf;

	buf = NULL;
	while (*s)
	{
		if(*s == (char)c)
			buf = s;
		s++;
	}
	if (*s = (char)c)
		return (s);
	return (buf);
}
