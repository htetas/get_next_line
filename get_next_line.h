/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:40:54 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/10 15:21:27 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*s;
	struct s_list	*next;
}	t_list;

char	*ft_strdup(const char *s);
t_list	*ft_lstnew(char *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_clean(t_list **lst);
size_t	ft_len_to_newline(t_list *lst);
int		ft_found_newline(t_list *lst);
void	ft_append(t_list **lst, char *buf);
void	ft_createlst(t_list **lst, int fd);
void	ft_cleanlst(t_list **lst);
char	*ft_get_line(t_list *lst);
char	*get_next_line(int fd);

#endif