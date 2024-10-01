/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:40:54 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/01 15:17:13 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFF_SIZE
# define BUFF_SIZE	10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_list
{
	char			*s;
	struct s_list	*next;
}	t_list;

#endif