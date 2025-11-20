#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;
	char	*ptr;

	nbr = ft_itoa(n);
	ptr = nbr;
	while (*ptr)
	{
		write(fd, &*ptr, 1);
		ptr++;
	}
	free(nbr);
}
