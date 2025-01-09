/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:33:00 by agraille          #+#    #+#             */
/*   Updated: 2025/01/09 12:44:36 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_cmd(char *cmd, char *way)
{
    int pipefd[2];
    int pid1;

    if (pipe(pipefd) == -1)
        return (-1);
	
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    return (0);
}
