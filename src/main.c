/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:14:58 by agraille          #+#    #+#             */
/*   Updated: 2025/01/11 21:56:08 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// acces verfie si permissio dacceder au fichier ou repertoire

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{	
	char **path;

	if (argc < 5)
		exit(EXIT_FAILURE); //prevoir un message derreur 
		
	path = path_split(envp);
	run_pipex(argv, path, argc);
	// if (fd != -1)
	// 	close (fd); CLOSE TOUT LES FD A LA FIN DU PROGRAMME
	ft_free(path);
	return (0);
}
