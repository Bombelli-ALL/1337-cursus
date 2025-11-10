/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:35:48 by alerradi          #+#    #+#             */
/*   Updated: 2025/11/09 21:44:07 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	i = ft_print_hex((unsigned long)s, 'x');
	return (i + 2);
}
