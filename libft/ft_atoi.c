/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:43:30 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/19 14:25:32 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == ' ')
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (res * sign);
}
