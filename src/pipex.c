/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:13:05 by agraille          #+#    #+#             */
/*   Updated: 2025/01/16 06:57:07 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	return (fd);
}

void	run_pipex(char **cmd, char **path, int argc, int i)
{
	int	infile;
	int	outfile;

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
	while (i < argc - 2)
		pipe_time(cmd[i++], path, outfile);
	to_outfile(outfile, cmd[i], path);
	waitpid(0, NULL, 0);
}
