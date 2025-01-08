/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:13:05 by agraille          #+#    #+#             */
/*   Updated: 2025/01/08 08:48:48 by agraille         ###   ########.fr       */
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
	return (path);
}

static int	check_open(char *check)
{
	int	fd;

	fd = open(check, O_TRUNC, O_WRONLY, O_RDONLY);
		if (!fd)
		{
			perror("Erreur lors de l'ouverture du fichier");
			return(0);
		}
	close (fd);
	return (1);
}

static int	check_acces(char *check)
{
	if(access(check, X_OK) == 0)
		return (1);
	perror("Erreur lors de l'acces a la commande");
	return (-1);
}

int	argv_is_valid(char **argv)
{
	int	i;

	i = 3;
	if (!check_open(argv[1]) || !argv[1])
		exit(EXIT_FAILURE);
	if (!check_acces(argv[2]) || !argv[2])
		exit(EXIT_FAILURE);
	while (argv[i])
	{
		if (i % 2 != 0)
		{
			if (!check_acces(argv[i]))
				exit(EXIT_FAILURE);
			ft_printf("i = %d",i);
		}
		else
			if (!check_open(argv[i]))
				exit(EXIT_FAILURE);
			
		i++;
	}
	return (0);
}
