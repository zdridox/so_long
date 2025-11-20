#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int i;
	t_list *p;

	i = 0;
	p = lst;
	if (p == NULL)
		return (0);
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return (i + 1);
}