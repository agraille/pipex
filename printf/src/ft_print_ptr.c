/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:02:16 by agraille          #+#    #+#             */
/*   Updated: 2025/01/02 08:31:17 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_ptr(unsigned long int args)
{
	char	buffer[42];
	char	*hex;
	size_t	len;
	size_t	i;

	if (args == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex = "0123456789abcdef";
	len = 2;
	i = 0;
	write(1, "0x", 2);
	while (args)
	{
		buffer[i] = hex[args % 16];
		args = args / 16;
		i++;
	}
	while (i--)
		len += ft_putchar(buffer[i]);
	return (len);
}
