/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 02:02:30 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/22 17:21:50 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

t_stack	*check_check(int ac, char **av)
{
	t_stack	*stack;
	int		*result_array;
	int		total_numbers;

	total_numbers = validate_and_count(ac, av);
	if (total_numbers == -1)
		return (write(2, "Error\n", 6), NULL);
	result_array = fill_array(ac, total_numbers, av);
	if (!result_array)
		return (write(2, "Error\n", 6), NULL);
	if (!check_duplicate(result_array, total_numbers))
	{
		free(result_array);
		return (write(2, "Error\n", 6), NULL);
	}
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (free(result_array), NULL);
	stack->num_a = result_array;
	stack->size_a = total_numbers;
	stack->num_b = malloc(sizeof(int) * total_numbers);
	if (!stack->num_b)
		return (free(stack->num_a), free(stack), NULL);
	stack->size_b = 0;
	return (stack);
}

int	convert(char *ptr)
{
	if (ft_strcmp(ptr, "sa\n") == 0)
		return (0);
	else if (ft_strcmp(ptr, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(ptr, "ss\n") == 0)
		return (2);
	else if (ft_strcmp(ptr, "pa\n") == 0)
		return (3);
	else if (ft_strcmp(ptr, "pb\n") == 0)
		return (4);
	else if (ft_strcmp(ptr, "ra\n") == 0)
		return (5);
	else if (ft_strcmp(ptr, "rb\n") == 0)
		return (6);
	else if (ft_strcmp(ptr, "rr\n") == 0)
		return (7);
	else if (ft_strcmp(ptr, "rra\n") == 0)
		return (8);
	else if (ft_strcmp(ptr, "rrb\n") == 0)
		return (9);
	else if (ft_strcmp(ptr, "rrr\n") == 0)
		return (10);
	else
		return (-1);
}

void	checker(t_stack *stack, int a)
{
	if (a == 0)
		sa(stack);
	if (a == 1)
		sb(stack);
	if (a == 2)
		ss(stack);
	if (a == 3)
		pa(stack);
	if (a == 4)
		pb(stack);
	if (a == 5)
		ra(stack);
	if (a == 6)
		rb(stack);
	if (a == 7)
		rr(stack);
	if (a == 8)
		rra(stack);
	if (a == 9)
		rrb(stack);
	if (a == 10)
		rrr(stack);
}

int	check2(t_stack *stack)
{
	int	a;

	a = -3;
	while (1)
	{
		a = get_next_line(0);
		if (a == -2)
			return (0);
		if (a == -1)
			return (write(2, "Error\n", 6), 1);
		checker(stack, a);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		return (0);
	stack = check_check(ac, av);
	if (!stack)
		return (1);
	if (check2(stack))
	{
		free(stack->num_b);
		free(stack->num_a);
		free(stack);
		return (1);
	}
	if (stack->size_b == 0 && check_sorted(stack->num_a, stack->size_a, 0))
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free(stack->num_b);
	free(stack->num_a);
	free(stack);
	return (0);
}
