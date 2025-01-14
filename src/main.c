/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:14:58 by agraille          #+#    #+#             */
/*   Updated: 2025/01/14 11:37:31 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	int		i;

	i = 2;
	if (argc != 5)
	{
		ft_putendl_fd("Example: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(EXIT_FAILURE);
	}
	path = path_split(envp);
	run_pipex(argv, path, argc, i);
	ft_free(path);
	return (0);
}
