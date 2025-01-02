/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:46:22 by agraille          #+#    #+#             */
/*   Updated: 2025/01/02 08:30:57 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_check(const char *format)
{
	char	*buffer;

	buffer = "cspdiuxX%";
	while (*buffer)
	{
		if (*buffer == *(format + 1))
			return (1);
		buffer++;
	}
	return (0);
}

static int	ft_args_is_valid(const char *format, va_list args)
{
	size_t	len_print;

	len_print = 0;
	format++;
	if (*format == 'c')
		len_print += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		len_print += ft_printstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		len_print += ft_printnbr(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		len_print += ft_print_hex(va_arg(args, unsigned int), format);
	else if (*format == 'u')
		len_print += ft_putnbr(va_arg(args, unsigned int));
	else if (*format == 'p')
		len_print += ft_print_ptr(va_arg(args, unsigned long int));
	else if (*format == '%')
	{
		write(1, "%", 1);
		len_print++;
	}
	return (len_print);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	size_t			total_printed;

	total_printed = 0;
	if (!format || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && ft_check(format))
		{
			total_printed += ft_args_is_valid(format, args);
			format ++;
		}
		else
		{
			write(1, format, 1);
			total_printed += 1;
		}
		format++;
	}
	va_end(args);
	return (total_printed);
}
