/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:15:48 by agraille          #+#    #+#             */
/*   Updated: 2025/01/12 01:26:27 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include "../printf/include/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>


char	**path_split(char **envp);
void	ft_free(char **path);
void	run_pipex(char **argv, char **path, int argc);
void	pipe_time(char *check, char **way);
void	exec(char *cmd, char **env);
char	*check_acces(char *cmd, char **path);


#endif
