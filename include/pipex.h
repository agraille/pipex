/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:15:48 by agraille          #+#    #+#             */
/*   Updated: 2025/01/08 08:28:07 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include "../printf/include/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>

char	**path_split(char **envp);
void	ft_free(char **path);
int	argv_is_valid(char **argv);

#endif
