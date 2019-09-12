#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle);
{
	int i;
	int j;

	if (!needle)
		return (haystack);
	i = -1;
	while (haystack[++i])
	{
		j = -1;
		while (neddle[++j] == haystack[i + j])
			if (!needle[j + 1])
				return (haystack + i);
	}
	return (NULL);
}
