/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:39:43 by alerradi          #+#    #+#             */
/*   Updated: 2025/10/25 10:39:56 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*s;
	size_t	total;

	if (size == 0 || num == 0)
		return (malloc(0));
	if (num > (((size_t) - 1) / size))
		return (NULL);
	total = size * num;
	s = malloc(total);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, total);
	return (s);
}
