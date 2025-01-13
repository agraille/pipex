/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:33:00 by agraille          #+#    #+#             */
/*   Updated: 2025/01/13 15:55:27 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*check_acces(char *cmd, char **path)
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

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit(EXIT_FAILURE);
	path = check_acces(s_cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free(s_cmd);
		ft_free(env);
		exit(EXIT_FAILURE);
	}
	execve(path, s_cmd, env);
}

void	pipe_time(char *cmd, char **path, int outfile)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit_time(outfile, path);
	pid = fork();
	if (pid == -1)
	{
		close(p_fd[0]);
		exit_time(p_fd[1], path);
	}
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		close(p_fd[1]);
		exec(cmd, path);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		close(p_fd[0]);
		waitpid(pid, NULL, 0);
	}
}
