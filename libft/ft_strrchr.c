/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:08:24 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/18 21:44:20 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*h;

	h = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			h = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (h);
}
