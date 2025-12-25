/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:30:07 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/22 17:22:44 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack *stack)
{
	int	first;

	if (stack->size_a < 2)
		return ;
	first = stack->num_a[0];
	ft_memmove(&stack->num_a[0], &stack->num_a[1], stack->size_a - 1);
	stack->num_a[stack->size_a - 1] = first;
}

void	rb(t_stack *stack)
{
	int	first;

	if (stack->size_b < 2)
		return ;
	first = stack->num_b[0];
	ft_memmove(&stack->num_b[0], &stack->num_b[1], stack->size_b - 1);
	stack->num_b[stack->size_b - 1] = first;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}

void	rra(t_stack *stack)
{
	int	last;

	if (stack->size_a < 2)
		return ;
	last = stack->num_a[stack->size_a - 1];
	ft_memmove(&stack->num_a[1], &stack->num_a[0], stack->size_a - 1);
	stack->num_a[0] = last;
}

void	rrb(t_stack *stack)
{
	int	last;

	if (stack->size_b < 2)
		return ;
	last = stack->num_b[stack->size_b - 1];
	ft_memmove(&stack->num_b[1], &stack->num_b[0], stack->size_b - 1);
	stack->num_b[0] = last;
}
