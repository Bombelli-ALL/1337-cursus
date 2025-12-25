/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_digits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:08:45 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/21 16:21:48 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_stack *stack, int range)
{
	int	limit;
	int	i;

	i = 0;
	while (stack->size_a > 0)
	{
		limit = i + range;
		if (stack->num_a[0] <= i)
		{
			pb(stack);
			rb(stack, 1);
			i++;
		}
		else if (stack->num_a[0] <= limit)
		{
			pb(stack);
			i++;
		}
		else
			ra(stack, 1);
	}
}

void	push_condition(t_stack *stack, int max)
{
	if (stack->num_b[0] == max - 1)
		pa(stack);
	else if (stack->max_i <= stack->size_b / 2)
	{
		while (stack->num_b[0] != max)
		{
			if (stack->num_b[0] == max - 1)
				pa(stack);
			else
				rb(stack, 1);
		}
		pa(stack);
	}
	else
	{
		while (stack->num_b[0] != max)
		{
			if (stack->num_b[0] == max - 1)
				pa(stack);
			else
				rrb(stack);
		}
		pa(stack);
	}
}

void	push_b_to_a(t_stack *stack)
{
	int	max;

	while (stack->size_b > 0)
	{
		max = get_max_val(stack);
		push_condition(stack, max);
		if (stack->size_a > 1 && stack->num_a[0] > stack->num_a[1])
			sa(stack);
	}
}

void	sort_large(t_stack *stack)
{
	int	range;

	range = 15;
	if (stack->size_a > 100)
		range = 30;
	push_a_to_b(stack, range);
	push_b_to_a(stack);
}

void	sort_small(t_stack *stack)
{
	if (stack->size_a == 2)
	{
		if (stack->num_a[0] > stack->num_a[1])
			sa(stack);
		return ;
	}
	while (stack->size_a > 3)
	{
		find_min(stack);
		if (stack->min_i <= stack->size_a / 2)
		{	
			while (stack->min_i-- > 0)
				ra(stack, 1);
		}
		else
		{
			while (stack->min_i++ < stack->size_a)
				rra(stack);
		}
		pb(stack);
	}
	sort_three(stack);
	while (stack->size_b > 0)
		pa(stack);
}
