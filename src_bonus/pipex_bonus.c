/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:13:05 by agraille          #+#    #+#             */
/*   Updated: 2025/01/16 06:56:04 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	here_in(char **cmd, int *p_fd)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (ft_strncmp(str, cmd[2], ft_strlen(cmd[2])) == 0)
		{
			free(str);
			close(p_fd[1]);
			exit(0);
		}
		ft_putstr_fd(str, p_fd[1]);
		free(str);
	}
}

static void	here_doc(char **cmd, char **path, int outfile)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		close(p_fd[0]);
		close(outfile);
		ft_free(path);
		here_in(cmd, p_fd);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		close(p_fd[0]);
		waitpid(pid, NULL, 0);
	}
}

static void	to_outfile(int outfile, char *cmd, char **path)
{
	int	last_pid;

	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	last_pid = fork();
	if (last_pid == 0)
		exec(cmd, path);
	waitpid(last_pid, NULL, 0);
}

static int	open_fd(char *cmd, int in_out)
{
	int	fd;

	fd = 0;
	if (in_out == 0)
	{
		fd = open(cmd, O_RDONLY, 0777);
		if (fd == -1)
			ft_putendl_fd("infile: Permission denied / doesn't exist", 2);
	}
	else if (in_out == 1)
	{
		fd = open(cmd, O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (fd == -1)
			ft_putendl_fd("outfile: Permission denied / doesn't exist", 2);
	}
	else if (in_out == 2)
	{
		fd = open(cmd, O_APPEND | O_CREAT | O_WRONLY, 0777);
		if (fd == -1)
			ft_putendl_fd("outfile: Permission denied / doesn't exist", 2);
	}
	return (fd);
}

void	run_pipex(char **cmd, char **path, int argc, int i)
{
	int	infile;
	int	outfile;

	if (i == 3)
	{
		outfile = open_fd(cmd[argc - 1], 2);
		here_doc(cmd, path, outfile);
	}
	else
	{
		infile = open_fd(cmd[1], 0);
		if (infile != -1)
		{
			dup2(infile, STDIN_FILENO);
			close(infile);
		}
		if (infile == -1)
			i++;
		outfile = open_fd(cmd[argc - 1], 1);
		if (outfile == -1)
			exit_time(infile, path);
	}
	while (i < argc - 2)
		pipe_time(cmd[i++], path, outfile);
	to_outfile(outfile, cmd[i], path);
	waitpid(0, NULL, 0);
}
