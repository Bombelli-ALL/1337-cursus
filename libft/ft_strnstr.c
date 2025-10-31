/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:10:30 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/19 14:18:02 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	leen;
	size_t	j;
	size_t	i;

	leen = (size_t)ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && len > i)
	{
		j = 0;
		while (j < leen && (i + j) < len && big[i + j] == little[j])
			j++;
		if (j == leen)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
