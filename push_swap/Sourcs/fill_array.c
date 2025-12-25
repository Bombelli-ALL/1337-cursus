/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:18:45 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/20 22:20:02 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_fill(char **av, char *pt, int count, int *j)
{
	int	k;

	k = 0;
	if (av[count][(*j)] == '-' || av[count][*j] == '+')
		pt[k++] = av[count][(*j)++];
	while (av[count][*j] == '0')
		(*j)++;
	while (isd(av[count][*j]))
	{
		if (k < 24)
			pt[k++] = av[count][(*j)++];
		else
			return (-1);
	}
	pt[k] = '\0';
	return (0);
}

int	extract_num(char **av, int *ptr, int count, int *i)
{
	char	pt[25];
	int		j;
	long	tmp;

	j = 0;
	while (av[count][j])
	{
		if (av[count][j] == '-' || av[count][j] == '+' || isd(av[count][j]))
		{
			if (check_fill(av, pt, count, &j) == -1)
				return (-1);
			tmp = ft_atol(pt);
			if (tmp > INT_MAX || tmp < INT_MIN)
				return (-1);
			ptr[(*i)++] = (int)tmp;
		}
		else
			j++;
	}
	return (0);
}

int	*fill_array(int ac, int total, char **av)
{
	int	*ptr;
	int	i;
	int	a;

	ptr = (int *)malloc(sizeof(int) * total);
	if (!ptr)
		return (NULL);
	i = 0;
	a = 1;
	while (a < ac)
	{
		if (extract_num(av, ptr, a, &i) == -1)
		{
			free(ptr);
			return (NULL);
		}
		a++;
	}
	return (ptr);
}
