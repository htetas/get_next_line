/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:18:46 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/23 11:39:40 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_append(t_list **lst, char *buf)
{
	t_list	*lastlst;
	t_list	*newlst;

	newlst = ft_lstnew(buf);
	if (newlst == NULL)
		return ;
	if (*lst == NULL)
		*lst = newlst;
	else
	{
		lastlst = *lst;
		while (lastlst->next)
			lastlst = lastlst->next;
		lastlst->next = newlst;
	}
}

void	ft_createlst(t_list **lst, int fd)
{
	char	*buf;
	ssize_t	char_read;

	while (!ft_found_newline(*lst))
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
			ft_clean(lst);
		if (char_read <= 0)
		{
			free (buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_append(lst, buf);
		free(buf);
	}
}

void	ft_cleanlst(t_list **lst)
{
	t_list	*last_node;
	char	*buf;
	int		j;

	if (*lst == NULL)
		return ;
	last_node = *lst;
	while (last_node->next)
		last_node = last_node->next;
	j = 0;
	while (last_node->s[j] != '\n' && last_node->s[j] != '\0')
		j++;
	if (last_node->s[j] == '\n')
		j++;
	buf = ft_strdup((const char *)last_node->s + j);
	ft_clean(lst);
	if (buf[0] != '\0')
		ft_append(lst, buf);
	free(buf);
}

char	*ft_get_line(t_list *lst)
{
	char	*next_line;
	int		i;
	int		j;

	j = 0;
	next_line = (char *)malloc((sizeof(char) * ft_len_to_newline(lst)) + 1);
	if (next_line == NULL)
		return (NULL);
	while (lst)
	{
		i = 0;
		while (lst->s[i] != '\n' && lst->s[i])
		{
			next_line[j] = lst->s[i];
			i++;
			j++;
		}
		if (lst->s[i] == '\n')
			next_line[j++] = '\n';
		lst = lst->next;
	}
	next_line[j] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	char			*next_line;
	static t_list	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_createlst(&lst, fd);
	if (!lst)
		return (NULL);
	next_line = ft_get_line(lst);
	if (!next_line)
		return (NULL);
	ft_cleanlst(&lst);
	return (next_line);
}
