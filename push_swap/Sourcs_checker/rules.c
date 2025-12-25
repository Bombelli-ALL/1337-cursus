/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:18:50 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/21 02:02:19 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->num_a[0];
	stack->num_a[0] = stack->num_a[1];
	stack->num_a[1] = temp;
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->num_b[0];
	stack->num_b[0] = stack->num_b[1];
	stack->num_b[1] = temp;
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
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
