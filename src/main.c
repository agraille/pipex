/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:14:58 by agraille          #+#    #+#             */
/*   Updated: 2025/01/07 10:49:38 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// acces verfie si permissio dacceder au fichier ou repertoire

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{	
	char **path;
	
	argc++;
	argv++;
	path = path_split(envp);
	ft_free(path);
	return (0);
}
