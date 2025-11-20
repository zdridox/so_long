#include "libft.h"

void	*ft_memset(void *ptr, unsigned int c, size_t n)
{
	unsigned char	*p;

	p = ptr;
	while (n--)
		*p++ = (unsigned char)c;
	return (ptr);
}
