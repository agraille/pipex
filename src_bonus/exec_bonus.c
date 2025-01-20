/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:33:00 by agraille          #+#    #+#             */
/*   Updated: 2025/01/19 21:51:40 by agraille         ###   ########.fr       */
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

static void	quotes(char **result, char **cmd, t_parse *p)
{
	if ((**cmd == '\'' || **cmd == '\"') && !p->in_quotes)
	{
		p->quote_char = **cmd;
		p->in_quotes = 1;
		p->start = *cmd + 1;
	}
	else if (**cmd == p->quote_char && p->in_quotes)
	{
		result[p->i] = ft_substr(p->start, 0, *cmd - p->start);
		p->i++;
		p->in_quotes = 0;
		p->quote_char = 0;
		p->start = *cmd + 1;
	}
}

static char	**parse_cmd_with_quotes(char *cmd, char	**result)
{
	t_parse	p;

	parce_init(&p);
	p.start = cmd;
	while (*cmd)
	{
		quotes(result, &cmd, &p);
		if (*cmd == ' ' && !p.in_quotes)
		{
			if (cmd > p.start)
				result[p.i++] = ft_substr(p.start, 0, cmd - p.start);
			while (*cmd == ' ')
				cmd++;
			p.start = cmd;
			continue ;
		}
		cmd++;
	}
	if (cmd > p.start)
		result[p.i++] = ft_substr(p.start, 0, cmd - p.start);
	result[p.i] = NULL;
	return (result);
}

void	exec(char *cmd, char **env, t_pid *s)
{
	char	**s_cmd;
	char	*path;

	s_cmd = malloc(sizeof(char *) * (ft_strlen(cmd) + 1));
	if (!s_cmd)
	{
		free(s);
		ft_free(env);
		exit(EXIT_FAILURE);
	}
	s_cmd = parse_cmd_with_quotes(cmd, s_cmd);
	path = check_acces(s_cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		free(s);
		ft_free(s_cmd);
		ft_free(env);
		exit(EXIT_FAILURE);
	}
	execve(path, s_cmd, env);
	exit(1);
}

void	pipe_time(char *cmd, char **path, int outfile, t_pid *s)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit_time(outfile, path, s);
	pid = fork();
	if (pid == -1)
		return (close(p_fd[0]), exit_time(p_fd[1], path, s));
	if (pid == 0)
	{
		close(outfile);
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		close(p_fd[1]);
		exec(cmd, path, s);
		exit(1);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		close(p_fd[0]);
		s->tab[s->index] = pid;
		s->index++;
	}
}
