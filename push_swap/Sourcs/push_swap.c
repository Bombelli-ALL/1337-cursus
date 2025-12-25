/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:09:10 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/20 19:46:16 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*check(int ac, char **av)
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

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		return (0);
	stack = check(ac, av);
	if (!stack)
		return (1);
	if (!check_sorted(stack->num_a, stack->size_a, 0))
	{
		if (stack->size_a == 3)
			sort_three(stack);
		else if (stack->size_a <= 5)
			sort_small(stack);
		else if (convert_to_ranks(stack))
			sort_large(stack);
	}
	free(stack->num_b);
	free(stack->num_a);
	free(stack);
	return (0);
}
