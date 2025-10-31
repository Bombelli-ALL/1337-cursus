/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:29:38 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/25 10:42:33 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	lens;
	char	*dest;

	if (!s || f == NULL)
		return (NULL);
	lens = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (lens + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= lens && s[i] != '\0')
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[lens] = '\0';
	return (dest);
}
