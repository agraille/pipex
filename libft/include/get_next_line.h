/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:44:22 by agraille          #+#    #+#             */
/*   Updated: 2024/12/19 09:44:56 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX 1024

typedef struct s_gnl
{
	char			content[BUFFER_SIZE + 1];
	struct s_gnl	*next;
}	t_chain;

char		*ft_strchr(char *s, int c);
void		ft_free_chain(t_chain **buffer);
ssize_t		ft_strlen(char *s);
char		*ft_copy(char *line, size_t len, t_chain **buffer, size_t j);
void		*ft_memmove(void *dest, const void *src, ssize_t n);
t_chain		*ft_add(t_chain **buffer);

#endif
