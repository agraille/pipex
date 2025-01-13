/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:14:58 by agraille          #+#    #+#             */
/*   Updated: 2025/01/13 09:33:13 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	int		i;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc < 6)
	{
		ft_putendl_fd("Example: ./pipex here_doc EOF cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc < 5)
	{
		ft_putendl_fd("Example: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i = 3;
	else
		i = 2;
	path = path_split(envp);
	run_pipex(argv, path, argc, i);
	ft_free(path);
	return (0);
}
