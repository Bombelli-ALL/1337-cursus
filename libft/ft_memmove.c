/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:36:49 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/18 20:44:55 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s && n > 0)
		ft_memcpy(d, s, n);
	else if (d > s && n > 0)
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n > 0)
		{
			*d-- = *s--;
			n--;
		}
	}
	return (dest);
}
