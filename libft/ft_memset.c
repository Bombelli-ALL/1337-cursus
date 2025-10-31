/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:02:41 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/31 00:30:27 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)s;
	while (s && n > 0)
	{
		*dest = c;
		dest++;
		n--;
	}
	return (s);
}
