/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:16:28 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/21 02:01:08 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

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
int		ft_strcmp(const char *s1, const char *s2);
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

// rules

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rrb(t_stack *stack);
void	rra(t_stack *stack);
void	rrr(t_stack *stack);

#endif