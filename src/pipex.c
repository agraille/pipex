/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:13:05 by agraille          #+#    #+#             */
/*   Updated: 2025/01/12 23:20:36 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <string.h>


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

static int	open_fd(char *cmd, int in_out)
{
	int	fd;

	if (in_out == 0)
		fd = open(cmd, O_RDONLY, 0777);
	if (in_out == 1)
		fd = open(cmd, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (in_out == 2)
		fd = open(cmd, O_APPEND | O_CREAT | O_WRONLY, 0777);
	return (fd);
}

char	*check_acces(char *cmd, char **path)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	temp2 = ft_strjoin("/", cmd);
	while (path[i])
	{
		temp = ft_strjoin(path[i], temp2);
		if (access(temp, F_OK | X_OK) == 0)
		{
			free(temp2);
			return (temp);
		}
		free(temp);
		i++;
	}
	free(temp2);
	return (NULL);
}

void	run_pipex(char **cmd, char **path, int argc)
{
	int	i;
	int	infile;
	int	outfile;

	if (strcmp(cmd[1], "here_doc") == 0)
	{
		// if (argc < 6)
		// 	exit(EXIT_FAILURE);
		i = 3;
		outfile = open_fd(cmd[argc - 1], 2);
		here_doc(cmd);
	}
	else
	{
		i = 2;
		infile = open_fd(cmd[1], 0);
		if (infile == -1)
		{
			ft_putendl_fd("Invalid infile\n", 2);
			ft_free(path);
			exit(EXIT_FAILURE);
		}
		outfile = open_fd(cmd[argc - 1], 1);
		if (outfile == -1)
		{
			ft_free(path);
			close(infile);
			exit(EXIT_FAILURE);
		}
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	while (i < argc - 2)
		pipe_time(cmd[i++], path, outfile);
	to_outfile(outfile, cmd[i], path);
}
