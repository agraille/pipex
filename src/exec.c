/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:33:00 by agraille          #+#    #+#             */
/*   Updated: 2025/01/12 23:19:04 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	here_in(char **cmd, int *p_fd)
{
	char	*str;

	close(p_fd[0]);
	while (1)
	{
		str = get_next_line(0);
		if (ft_strncmp(str, cmd[2], ft_strlen(cmd[2])) == 0)
		{
			free(str);
			exit(0);
		}
		ft_putstr_fd(str, p_fd[1]);
		free(str);
	}
}

void	here_doc(char **cmd)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
		here_in(cmd, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

void	exec(char *cmd, char **env, int outfile)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit(EXIT_FAILURE);
	path = check_acces(s_cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free(s_cmd);
		free(path);
		ft_free(env);
		close(outfile);
		exit(EXIT_FAILURE);
	}
	execve(path, s_cmd, env);
}

void	to_outfile(int outfile, char *cmd, char **path)
{
	int	last_pid;

	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	last_pid = fork();
	if (last_pid == 0)
	{
		exec(cmd, path, outfile);
	}	
	waitpid(last_pid, NULL, 0);
}

int	pipe_time(char *cmd, char **path, int outfile)
{
	int	pid;
	int	p_fd[2];

	if (pipe(p_fd) == -1)
	{
		perror("PIPE");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		perror("FORK");
		return (-1);
	}
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		close(p_fd[1]);
		exec(cmd, path, outfile);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		close(p_fd[0]);
		waitpid(pid, NULL, 0);
	}
	return (1);
}
