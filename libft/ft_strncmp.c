#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = -1;
	while (++i < n && *s1)
		if (ft_memcmp(&s1[i], &s2[i]))
			return (ft_memcmp(&s1[i], &s2[i]));
	return (0);
}
