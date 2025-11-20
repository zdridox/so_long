#include "libft.h"

void	ft_bzero(void *src, size_t n)
{
	unsigned char	*c;

	c = src;
	while (n-- > 0)
		*c++ = '\0';
}
