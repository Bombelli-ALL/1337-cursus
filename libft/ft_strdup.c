/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:36:37 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/25 10:36:45 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (l + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, l + 1);
	return (dest);
}
