/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:12:22 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/20 14:54:52 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

// check_nums

int		validate_and_count(int ac, char **av);
int		check_duplicate(int *arr, int size);
int		check_sorted(int *arr, int size, int mode);

// fill_array

int		*fill_array(int ac, int total, char **av);

// libft

void	swap_values(int *a, int *b);
void	ft_memmove(int *dest, int *src, size_t n);
int		isd(int c);
long	ft_atol(const char *ptr);

// Database

typedef struct s_stack{
	int	*num_a;
	int	*num_b;
	int	size_a;
	int	size_b;
	int	min_i;
	int	max_i;
}	t_stack;

//mian

t_stack	*check(int ac, char **av);

//sorted_digits

int		*get_sorted_copy(t_stack *stack);
int		convert_to_ranks(t_stack *stack);
void	sort_small(t_stack *stack);
void	sort_large(t_stack *stack);
void	sort_three(t_stack *stack);

//help

int		get_max_val(t_stack *stack);
void	find_min(t_stack *stack);

// Rules

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack, int mod);
void	rb(t_stack *stack, int mod);
void	rr(t_stack *stack);
void	rrb(t_stack *stack);
void	rra(t_stack *stack);

#endif