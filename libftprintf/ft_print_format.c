/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:58:47 by alerradi          #+#    #+#             */
/*   Updated: 2025/11/09 21:56:29 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		i += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(args, int), format);
	else if (format == 'u')
		i += ft_putnbr((unsigned int)va_arg(args, unsigned int), format);
	else if (format == 'x' || format == 'X')
		i += ft_print_hex((unsigned long)va_arg(args, unsigned int), format);
	else if (format == '%')
		i += ft_putchar('%');
	return (i);
}
