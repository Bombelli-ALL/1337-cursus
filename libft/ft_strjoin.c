/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:35:43 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/25 10:41:57 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	le1;
	size_t	le2;
	size_t	total;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	le1 = ft_strlen(s1);
	le2 = ft_strlen(s2);
	total = le1 + le2 + 1;
	ptr = (char *)malloc(sizeof(char) * total);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, total);
	ft_strlcat(ptr, s2, total);
	return (ptr);
}
