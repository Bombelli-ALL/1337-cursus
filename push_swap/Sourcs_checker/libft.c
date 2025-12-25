/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:26:14 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/22 17:21:16 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atol(const char *ptr)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		res = res * 10 + (*ptr - '0');
		if (res > INT_MAX)
			break ;
		ptr++;
	}
	return (res * sign);
}

int	isd(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_memmove(int *dest, int *src, size_t n)
{	
	size_t	i;

	i = 0;
	if (dest < src && n > 0)
	{
		while (n > i)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (dest > src && n > 0)
	{
		while (n-- > 0)
			dest[n] = src[n];
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
