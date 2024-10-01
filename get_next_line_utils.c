#include <get_next_line.h>

t_list	*ft_lstnew(char *content)
{
	t_list	*nlst;

	nlst = (t_list *)malloc(sizeof(t_list));
	if (nlst == NULL)
		return (NULL);
	nlst->s = content;
	nlst->next = NULL;
	return (nlst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

size_t	ft_findlen(t_list *lst)
{
	int		i;
	size_t	len;

	while (lst)
	{
		i = 0
		while (lst->s[i])
		{
			if (lst->s[i] == '\n')
				return (len + 1);
			i++;
			len++
		}
		lst = lst->next;
	}
}

int	ft_found_new_line(t_list *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (lst->s[i])
		{
			if (lst->s[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}