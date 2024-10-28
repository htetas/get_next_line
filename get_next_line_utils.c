/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:18:57 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/23 11:33:42 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	d = (char *) malloc((len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*nlst;

	nlst = (t_list *)malloc(sizeof(t_list));
	if (nlst == NULL)
		return (NULL);
	nlst->s = ft_strdup((const char *)content);
	if (nlst->s == NULL)
	{
		free(nlst);
		return (NULL);
	}
	nlst->next = NULL;
	return (nlst);
}

size_t	ft_len_to_newline(t_list *lst)
{
	size_t	i;
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

void	ft_clean(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->s);
		free(tmp);
	}
}
