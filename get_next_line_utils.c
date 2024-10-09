/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:18:57 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/09 13:28:17 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_len_to_newline(t_list *lst)
{
	int		i;
	size_t	len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->s[i])
		{
			if (lst->s[i] == '\n')
				return (len + 1);
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

int	ft_found_newline(t_list *lst)
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

void	ft_clean(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->s);
		tmp->s = NULL;
		free(tmp);
		tmp = NULL;
	}
}