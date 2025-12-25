/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:30:07 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/20 13:54:05 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int mod)
{
	int	first;

	first = stack->num_a[0];
	ft_memmove(&stack->num_a[0], &stack->num_a[1], stack->size_a - 1);
	stack->num_a[stack->size_a - 1] = first;
	if (mod)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int mod)
{
	int	first;

	first = stack->num_b[0];
	ft_memmove(&stack->num_b[0], &stack->num_b[1], stack->size_b - 1);
	stack->num_b[stack->size_b - 1] = first;
	if (mod)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	ra(stack, 0);
	rb(stack, 0);
	write(1, "rr\n", 3);
}

void	rra(t_stack *stack)
{
	int	last;

	last = stack->num_a[stack->size_a - 1];
	ft_memmove(&stack->num_a[1], &stack->num_a[0], stack->size_a - 1);
	stack->num_a[0] = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	int	last;

	last = stack->num_b[stack->size_b - 1];
	ft_memmove(&stack->num_b[1], &stack->num_b[0], stack->size_b - 1);
	stack->num_b[0] = last;
	write(1, "rrb\n", 4);
}
