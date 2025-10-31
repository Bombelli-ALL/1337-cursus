/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:55:16 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/31 00:28:08 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s;
	const unsigned char	*d;

	s = (const unsigned char *)s1;
	d = (const unsigned char *)s2;
	while (s && d && n > 0)
	{
		if (*s != *d)
			return (*s - *d);
		s++;
		d++;
		n--;
	}
	return (0);
}
