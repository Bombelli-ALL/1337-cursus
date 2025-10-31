/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:11:05 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/18 21:04:58 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (n <= d)
		return (n + s);
	i = 0;
	while (src[i] && (d + i) < n - 1)
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[i + d] = '\0';
	return (d + s);
}
