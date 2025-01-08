/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:14:58 by agraille          #+#    #+#             */
/*   Updated: 2025/01/08 08:47:23 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// acces verfie si permissio dacceder au fichier ou repertoire

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{	
	char **path;

	if (argc < 5)
		exit(EXIT_FAILURE);
		
	path = path_split(envp);
	argv_is_valid(argv);
	ft_free(path);
	return (0);
}
