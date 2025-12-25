/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:18:50 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/21 00:07:05 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->num_a[0];
	stack->num_a[0] = stack->num_a[1];
	stack->num_a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->num_b[0];
	stack->num_b[0] = stack->num_b[1];
	stack->num_b[1] = temp;
	write(1, "sb\n", 3);
}

void	pa(t_stack *stack)
{
	if (stack->size_b == 0)
		return ;
	ft_memmove(&stack->num_a[1], &stack->num_a[0], stack->size_a);
	stack->num_a[0] = stack->num_b[0];
	ft_memmove(&stack->num_b[0], &stack->num_b[1], stack->size_b - 1);
	(stack->size_b)--;
	(stack->size_a)++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	if (stack->size_a == 0)
		return ;
	ft_memmove(&stack->num_b[1], &stack->num_b[0], stack->size_b);
	stack->num_b[0] = stack->num_a[0];
	ft_memmove(&stack->num_a[0], &stack->num_a[1], stack->size_a - 1);
	(stack->size_a)--;
	(stack->size_b)++;
	write(1, "pb\n", 3);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->num_a[0];
	b = stack->num_a[1];
	c = stack->num_a[2];
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}
