/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:13:05 by agraille          #+#    #+#             */
/*   Updated: 2025/01/12 01:50:50 by agraille         ###   ########.fr       */
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

static int	open_fd(char *cmd, int in_out)
{
	int	fd;

	if (in_out == 0)
	{
		fd = open(cmd, O_RDONLY, 0777);
		if (!fd)
		{
			perror("FD");
			exit(EXIT_FAILURE);
		}
	}
	if (in_out == 1)
	{
		fd = open(cmd, O_WRONLY | O_TRUNC | O_CREAT, 0777);
			if (!fd)
			{
				perror("FD");
				exit(EXIT_FAILURE); //gerer erreur
			}
	}
	return (fd);
}

char	*check_acces(char *cmd, char **path)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;
	
	i = 0;
	j = 0;
	while (path[i])
	{
		temp2 = ft_strjoin("/",cmd);
		while (temp2[j] != ' ' && temp2[j])
			j++;
		temp2[j] = '\0';
		temp = ft_strjoin(path[i], temp2);
		free(temp2);
		if	(access(temp, F_OK | X_OK) == 0)
		{
			return (temp);
			free(temp);
		}
		i++;
	}
	free(temp);
	return (NULL);
}

void	run_pipex(char **cmd, char **path, int argc)
{
	int	i;
	int	infile;
	int	outfile;

	i = 2;
	infile = open_fd(cmd[1], 0);
	outfile = open_fd(cmd[argc - 1], 1);
	if (!outfile)
	{
		close(infile);
		exit(EXIT_FAILURE);
	}
	dup2(infile,STDIN_FILENO);
	while (i < argc - 2)
		pipe_time(cmd[i++], path);
	dup2(outfile,STDOUT_FILENO);
	exec(cmd[i], path);
	close(infile);
	close(outfile);
}
