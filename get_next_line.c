#include <get_next_line.h>

void	ft_append(t_list **lst, char *buf)
{
	t_list	*lastlst;
	t_list	*newlst;
	
	lastlst = ft_lstlast(lst);
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

	while (!ft_found_new_line(lst))
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

char	*ft_get_line(t_list **lst)
{
	char	*next_line;
	int		i;
	
	next_line = (char *)malloc((sizeof(char) * ft_findlen(lst)) + 1);
	if (next_line == NULL)
		return (NULL);
	while (lst)
}

char	*get_next_line(int fd)
{
	char	*next_line;
	t_list	*lst;

	lst = NULL;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	ft_createlst(&lst);
	if (lst == NULL)
		return (NULL);
	next_line = ft_get_line(lst);
}