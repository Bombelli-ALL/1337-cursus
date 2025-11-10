/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:35:39 by alerradi          #+#    #+#             */
/*   Updated: 2025/11/09 21:55:50 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, char format)
{
	int	i;

	i = 0;
	if (format != 'u' && n < 0)
	{
		ft_putchar('-');
		n *= -1;
		i++;
	}
	if (n > 9)
		i += ft_putnbr(n / 10, format);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
