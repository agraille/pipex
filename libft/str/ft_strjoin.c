/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:10:29 by agraille          #+#    #+#             */
/*   Updated: 2025/01/09 08:11:36 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_of_string_return;
	char	*tab_return;
	size_t	i;

	i = 0;
	size_of_string_return = ft_strlen(s1) + ft_strlen(s2);
	tab_return = malloc(size_of_string_return + 1);
	if (!tab_return)
		return (NULL);
	while (*s1)
	{
		tab_return[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		tab_return[i] = *s2;
		i++;
		s2++;
	}
	tab_return[i] = '\0';
	return (tab_return);
}
