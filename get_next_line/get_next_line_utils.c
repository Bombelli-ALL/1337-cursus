/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:51:52 by alerradi          #+#    #+#             */
/*   Updated: 2025/11/21 14:44:30 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, size_t le2)
{
	char	*ptr;
	size_t	le1;
	size_t	i;

	le1 = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (le1 + le2 + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1 && i < le1)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < le2)
	{
		ptr[le1 + i] = s2[i];
		i++;
	}
	ptr[le1 + i] = '\0';
	free(s1);
	return (ptr);
}

int	find_newline(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char)c)
	{	
		if (*s == '\0')
			return (0);
		s++;
	}
	return (1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (free(s), NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	if (dest[0] == '\0')
	{
		free(dest);
		dest = NULL;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
