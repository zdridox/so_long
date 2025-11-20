#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int main() {
//	char *strr = "test";
//	int i = ft_strlen(strr);
//	if(i == 4) {
//		write(1, "OK", 2);
//	}
//	return (0);
//}
