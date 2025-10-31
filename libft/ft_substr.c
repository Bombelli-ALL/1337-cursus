/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:30:07 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/25 10:41:05 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	total;
	size_t	sl;

	if (s == NULL)
		return (NULL);
	sl = ft_strlen(s);
	if (start > sl)
		return (ft_strdup(""));
	total = ft_strlen(s + start);
	if (len <= sl - start)
		total = len;
	dest = (char *)malloc(sizeof(char) * (total + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s + start, total);
	dest[total] = '\0';
	return (dest);
}
