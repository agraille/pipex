/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:14:58 by agraille          #+#    #+#             */
/*   Updated: 2025/01/19 18:01:23 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	wait_child(t_pid *s)
{
	int	i;
	int	status;

	i = 0;
	while (i < s->index)
	{
		waitpid(s->tab[i], &status, 0);
		i++;
	}
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	t_pid	*s;
	int		status;

	s = malloc(sizeof(t_pid));
	if (!s)
		exit(EXIT_FAILURE);
	if (argc < 5)
	{
		ft_putendl_fd("Example: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc >= 6
		&& (int)ft_strlen(argv[1]) == 8)
		s->i = 3;
	else
		s->i = 2;
	path = path_split(envp);
	s->index = 0;
	run_pipex(argv, path, argc, s);
	status = wait_child(s);
	ft_free(path);
	free(s);
	return (status);
}
