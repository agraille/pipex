/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:13:05 by agraille          #+#    #+#             */
/*   Updated: 2025/01/07 12:50:12 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	for (int j = 0; path[j]; j++)
		ft_printf(" %d = %s\n",j, path[j]);
	return (path);
}

static int	check_acces(char *check, int i)
{
	if(i % 2 == 0)
	{
		acces(check, W_OK);
		acces(check, R_OK);
	}
	else
	{
		acces(check, X_OK);
	}
	return (0);
}

int	argv_is_valid(char **argv)
{
	int	i;

	i = 3;
	if (!check_acces(argv[1], 2))
		exit(EXIT_FAILURE);
	if (!check_acces(argv[2], 1))
		exit(EXIT_FAILURE);
	while (argv[i])
	{
	if (!check_acces(argv[2], i))
		exit(EXIT_FAILURE);
	}
}
