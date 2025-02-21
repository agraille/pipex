/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:15:48 by agraille          #+#    #+#             */
/*   Updated: 2025/01/19 21:49:10 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include "../printf/include/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_parse
{
	int		i;
	int		in_quotes;
	char	quote_char;
	char	*start;
}	t_parse;

typedef struct s_pid
{
	int		i;
	int		index;
	int		tab[1024];
}	t_pid;

char	**path_split(char **envp);
void	ft_free(char **path);
void	run_pipex(char **argv, char **path, int argc, t_pid *s);
void	pipe_time(char *check, char **way, int outfile, t_pid *s);
void	exec(char *cmd, char **env, t_pid *s);
void	exit_time(int fd, char **path, t_pid *s);
void	parce_init(t_parse *p);

#endif
