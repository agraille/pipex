/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:33:00 by agraille          #+#    #+#             */
/*   Updated: 2025/01/10 12:24:48 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_cmd(char *cmd, char *way)
{
    int pid;
    int p_fd[2];

    if (pipe(p_fd) == -1)
    {
        perror("Erreur de pipe");
        exit(1);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Erreur de fork");
        exit(1);
    }

    if (pid == 0)
    {
        close(p_fd[0]);
        dup2(p_fd[1], STDOUT_FILENO);
        close(p_fd[1]); // Ferme l'extrémité d'écriture après duplication
        char *args[] = {cmd, NULL};  // Exemple avec une commande sans arguments supplémentaires
        execv(way, args);  // Exécuter la commande
        perror("Erreur lors de l'exécution de la commande");
        exit(1);
    }
    else
    {
        close(p_fd[1]);
        dup2(p_fd[0], STDIN_FILENO);
        close(p_fd[0]); // Ferme l'extrémité de lecture après duplication
        waitpid(pid, NULL, 0);  // Attends la fin de l'exécution de l'enfant
    }
}

