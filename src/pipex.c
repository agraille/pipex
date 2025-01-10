/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:13:05 by agraille          #+#    #+#             */
/*   Updated: 2025/01/10 12:10:42 by agraille         ###   ########.fr       */
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

	fd = open(check, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (!fd)
		{
			perror("Erreur lors de l'ouverture du fichier");
			return(-1);
		}
	return (fd);
}

static int	check_acces(char *argv, char **path)
{
	int		i;
	char	*temp;
	char	*temp2;
	
	i = 0;
	while (path[i])
	{
		temp2 = ft_strjoin("/", argv);
		temp = ft_strjoin(path[i], temp2);
		free(temp2);
		if	(access(temp, F_OK | X_OK) == 0)
		{
			free(temp);
			exec_cmd(argv, path[i]);
			return (1);
		}
		free(temp);
		i++;
	}
	return (-1);
}

int	argv_is_valid(char **argv, char **path)
{
	int	i;
	int	infile;

	i = 3;
	infile = open(argv[1], O_RDONLY);
	if (!infile)
		infile = check_open(argv[1]);
	if (dup2(infile,STDIN_FILENO) == -1)
		return (1);
	close(infile);
	while (argv[i])
	{
		if (!check_acces(argv[i], path))
			write(2, "ACCES KO\n", 9);
		i++;
	}
	check_open(argv[i - 1]);
	return (0);
}
