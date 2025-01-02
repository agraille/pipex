/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:48:53 by agraille          #+#    #+#             */
/*   Updated: 2024/12/18 08:08:07 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size_allocate;

	if ((size > ((size_t)-1) / nmemb))
		return (NULL);
	total_size_allocate = nmemb * size;
	if (total_size_allocate < 1)
		return (NULL);
	ptr = malloc(total_size_allocate);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size_allocate);
	return (ptr);
}
