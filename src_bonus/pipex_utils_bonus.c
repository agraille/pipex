/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:47:37 by agraille          #+#    #+#             */
/*   Updated: 2025/01/19 17:42:15 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

void	exit_time(int fd, char **path)
{
	ft_free(path);
	close(fd);
	exit(EXIT_FAILURE);
}

char	**path_split(char **envp)
{
	size_t	i;
	char	**path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path = ft_split(envp[i], ':');
			break ;
		}
		++i;
	}
	ft_memmove(path[0], path[0] + 5, ft_strlen(path[0]) - 4);
	return (path);
}

void	parce_init(t_parse *p)
{
	p->i = 0;
	p->in_quotes = 0;
	p->quote_char = 0;
}
