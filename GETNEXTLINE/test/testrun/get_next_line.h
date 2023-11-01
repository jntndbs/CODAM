/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: joni <joni@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 19:44:21 by joni          #+#    #+#                 */
/*   Updated: 2023/10/26 15:31:41 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# define BUFFER_SIZE 5

typedef struct s_list
{
	char			*buf;
	int				position;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(char *buf);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
char	*ft_strchr(const char *str, int c);
int		ft_lstsize(t_list *lst);

#endif