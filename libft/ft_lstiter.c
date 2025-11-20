#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	p = lst;
	if (p == NULL)
		return ;
	while (p)
	{
		f(p->content);
		p = p->next;
	}
}
