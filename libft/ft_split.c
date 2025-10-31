/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:37:00 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/30 16:28:13 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	total(char const *a, char b)
{
	int	num;
	int	j;

	j = 0;
	num = 0;
	while (*a)
	{
		if (*a == b)
			j = 0;
		else if (j == 0)
		{
			num++;
			j = 1;
		}
		a++;
	}
	return (num);
}

static size_t	ft_strleee(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

static char	**free_all(char **ptr, size_t p)
{
	while (p > 0)
	{
		p--;
		free(ptr[p]);
	}
	free(ptr);
	return (NULL);
}

static char	**heavy(char **pt, char const *s, char c, size_t size)
{
	size_t	u;
	size_t	p;
	size_t	leen;

	p = 0;
	u = 0;
	while (p < size)
	{
		while (s[u] && s[u] == c)
			u++;
		if (s[u])
		{
			leen = ft_strleee(s, c, u);
			pt[p] = ft_substr(s, u, leen);
			if (pt[p] == NULL)
				return (free_all(pt, p));
			u += leen;
		}
		p++;
	}
	pt[p] = NULL;
	return (pt);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	size;

	if (!s)
		return (NULL);
	size = total(s, c);
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	return (heavy(ptr, s, c, size));
}
