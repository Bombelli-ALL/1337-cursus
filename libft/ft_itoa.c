/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:39:11 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/25 10:43:09 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calcul(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	filler(char *dest, long n, size_t len)
{
	if (n < 0)
	{
		dest[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		dest[--len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	len;
	long	num;

	num = (long)n;
	len = calcul(num);
	if (num < 0)
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (num == 0)
		dest[0] = '0';
	else
		filler(dest, num, len);
	return (dest);
}
