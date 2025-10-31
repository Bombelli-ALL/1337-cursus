/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:02:04 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/31 00:27:39 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*h;

	h = (const unsigned char *)s;
	while (s && n > 0)
	{
		if (*h == (unsigned char)c)
			return ((void *)h);
		h++;
		n--;
	}
	return (NULL);
}
