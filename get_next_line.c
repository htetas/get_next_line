/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:18:46 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/09 14:06:20 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_append(t_list **lst, char *buf)
{
	t_list	*lastlst;
	t_list	*newlst;

	lastlst = ft_lstlast(*lst);
	newlst = ft_lstnew(buf);
	if (newlst == NULL)
		return ;
	if (lastlst == NULL)
		*lst = newlst;
	else
		lastlst->next = newlst;
}

void	ft_createlst(t_list **lst, int fd)
{
	char	*buf;
	int		char_read;

	while (!ft_found_newline(*lst))
	{
		buf = (char *)malloc((sizeof(char) * BUFF_SIZE) + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFF_SIZE);
		if (!char_read)
		{
			free (buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_append(lst, buf);
	}
}

void	ft_cleanlst(t_list **lst)
{
	t_list	*new_node;
	t_list	*last_node;
	char	*buf;
	int		i;
	int		j;

	last_node = ft_lstlast(*lst);
	buf = (char *)malloc((sizeof(char) * BUFF_SIZE) + 1);
	if (buf == NULL)
		return ;
	j = 0;
	while (last_node->s[j] != '\n' && last_node->s[j] != '\0')
		j++;
	i = 0;
	if (last_node->s[j] == '\n')
		j++;
	while (last_node->s[j] != '\0')
		buf[i++] = last_node->s[j++];
	buf[i] = '\0';
	new_node = ft_lstnew(buf);
	ft_clean(*lst);
	*lst = new_node;
}

char	*ft_get_line(t_list **lst)
{
	char	*next_line;
	int		i;
	int		j;

	j = 0;
	next_line = (char *)malloc((sizeof(char) * ft_len_to_newline(*lst)) + 1);
	if (next_line == NULL)
		return (NULL);
	while (*lst)
	{
		i = 0;
		while (*lst->s[i] != '\n')
		{
			next_line[j] = *lst->s[i];
			i++;
			j++;
		}
		*lst = *lst->next;
	}
	next_line[j++] = '\n';
	next_line[j] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	char	*next_line;
	t_list	*lst;

	lst = NULL;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	ft_createlst(&lst, fd);
	if (lst == NULL)
		return (NULL);
	next_line = ft_get_line(&lst);
	ft_cleanlst(&lst);
	return (next_line);
}
