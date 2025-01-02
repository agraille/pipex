/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:39:52 by agraille          #+#    #+#             */
/*   Updated: 2025/01/02 08:31:20 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_args_zero(unsigned int args)
{
	if (args == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

int	ft_print_hex(unsigned int args, const char *format)
{
	char			*hex_lowercase;
	char			*hex_uppercase;
	int				len;
	int				i;
	char			buffer[42];

	i = 0;
	len = ft_args_zero(args);
	hex_lowercase = "0123456789abcdef";
	hex_uppercase = "0123456789ABCDEF";
	while (args > 0)
	{
		if (*format == 'X')
			buffer[i] = hex_uppercase[args % 16];
		else if (*format == 'x')
			buffer[i] = hex_lowercase[args % 16];
		args = args / 16;
		len++;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar(buffer[i--]);
	return (len);
}
