#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *p;

	p = lst;
	if (p == NULL)
		return (0);
	while (p->next != NULL)
	{
		p = p->next;
	}
	return (p);
}