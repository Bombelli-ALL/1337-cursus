/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:35:16 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/25 10:42:12 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (ft_strdup(""));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (i < j && ft_strchr(set, s1[j]))
		j--;
	len = (j - i) + 1;
	ptr = ft_substr(s1, i, len);
	return (ptr);
}
