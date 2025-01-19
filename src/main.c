/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:14:58 by agraille          #+#    #+#             */
/*   Updated: 2025/01/19 18:11:22 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	wait_child(t_pid *s)
{
	int	i;

	i = 0;
	while (i < s->index)
	{
		waitpid(s->tab[i], NULL, 0);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	t_pid	*s;

	if (argc != 5)
	{
		ft_putendl_fd("Example: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(EXIT_FAILURE);
	}
	s = malloc(sizeof(t_pid));
	if (!s)
		exit(EXIT_FAILURE);
	s->i = 2;
	path = path_split(envp);
	s->index = 0;
	run_pipex(argv, path, argc, s);
	wait_child(s);
	ft_free(path);
	free(s);
	return (0);
}
