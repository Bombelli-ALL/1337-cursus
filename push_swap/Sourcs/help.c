/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:25:40 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/20 19:34:18 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *tab, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (tab[j] < pivot)
		{
			i++;
			swap_values(&tab[i], &tab[j]);
		}
		j++;
	}
	swap_values(&tab[i + 1], &tab[end]);
	return (i + 1);
}

void	quick_sort_recursive(int *tab, int start, int end)
{
	int	p_idx;

	if (start < end)
	{
		p_idx = partition(tab, start, end);
		quick_sort_recursive(tab, start, p_idx - 1);
		quick_sort_recursive(tab, p_idx + 1, end);
	}
}

int	*get_sorted_copy(t_stack *stack)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * stack->size_a);
	if (!tab)
	{
		free(stack->num_a);
		return (NULL);
	}
	while (i < stack->size_a)
	{
		tab[i] = stack->num_a[i];
		i++;
	}
	quick_sort_recursive(tab, 0, stack->size_a - 1);
	return (tab);
}

void	find_min(t_stack *stack)
{
	int	i;

	i = 0;
	stack->min_i = 0;
	while (i < stack->size_a)
	{
		if (stack->num_a[stack->min_i] >= stack->num_a[i])
			stack->min_i = i;
		i++;
	}
}

int	get_max_val(t_stack *stack)
{
	int	max;
	int	i;

	if (stack->size_b == 0)
		return (0);
	max = stack->num_b[0];
	i = 1;
	while (i < stack->size_b)
	{
		if (stack->num_b[i] > max)
		{
			max = stack->num_b[i];
			stack->max_i = i;
		}
		i++;
	}
	return (max);
}
