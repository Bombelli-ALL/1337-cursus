/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:26:34 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/22 16:29:50 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_nums_in_string(char *arg)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			i++;
		else
		{
			if (arg[i] == '-' || arg[i] == '+')
				i++;
			if (!isd(arg[i]))
				return (-1);
			while (isd(arg[i]))
				i++;
			if (arg[i] && arg[i] != ' ')
				return (-1);
			num++;
		}
	}
	if (!num)
		return (-1);
	return (num);
}

int	validate_and_count(int ac, char **av)
{
	int	total;
	int	help;

	total = 0;
	while (--ac)
	{
		help = count_nums_in_string(av[ac]);
		if (help == -1)
			return (-1);
		total += help;
	}
	if (!total)
		return (-1);
	return (total);
}

int	check_duplicate(int *arr, int size)
{
	int	j;
	int	i;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sorted(int *arr, int size, int mode)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (mode == 0)
		{
			if (arr[i] > arr[i + 1])
				return (0);
		}
		else if (mode == 1)
		{
			if (arr[i] < arr[i + 1])
				return (0);
		}
		i++;
	}
	return (1);
}
