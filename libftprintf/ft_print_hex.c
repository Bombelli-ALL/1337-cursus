/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:35:45 by alerradi          #+#    #+#             */
/*   Updated: 2025/11/09 21:45:14 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long x, char format)
{
	int		i;
	char	*he;
	char	*h;

	he = "0123456789abcdef";
	h = "0123456789ABCDEF";
	i = 0;
	if (x >= 16)
		i += ft_print_hex(x / 16, format);
	if (format == 'x')
		i += ft_putchar(he[x % 16]);
	else
		i += ft_putchar(h[x % 16]);
	return (i);
}
