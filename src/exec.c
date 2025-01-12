/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:33:00 by agraille          #+#    #+#             */
/*   Updated: 2025/01/12 13:25:49 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void exec(char *cmd, char **env)
{
    char **s_cmd;
    char *path;

    s_cmd = ft_split(cmd, ' ');
    if (!s_cmd)
        exit(EXIT_FAILURE);
    path = check_acces(s_cmd[0], env);
    if (!path)
    {
        ft_putstr_fd("pipex: command not found: ", 2);
        ft_putendl_fd(s_cmd[0], 2);
        ft_free(s_cmd);
        exit(EXIT_FAILURE);
    }
    execve(path, s_cmd, env);
    // Si on arrive ici, c'est que execve a échoué
    free(path);
    ft_free(s_cmd);
    perror("execve");
    exit(EXIT_FAILURE);
}

void	pipe_time(char *cmd, char **path)
{
    int pid;
    int p_fd[2];

    if (pipe(p_fd) == -1)
    {
        perror("PIPE");
        exit(1);// gerer la sortie 
    }
    pid = fork();
    if (pid == -1)
    {
        perror("FORK");
        exit(1);//gerer la sortie 
    }
    if (pid == 0)
    {
        close(p_fd[0]);
        dup2(p_fd[1], STDOUT_FILENO);
        close(p_fd[1]);
        exec(cmd, path);
		// ft_free(path);
        // exit(1);
    }
    else
    {
        close(p_fd[1]);
        dup2(p_fd[0], STDIN_FILENO);
        close(p_fd[0]);
        waitpid(pid, NULL, 0);
    }
}

