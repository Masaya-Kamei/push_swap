/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:19:14 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/29 13:35:40 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_status	atoi_with_check(char *str, int *nbr)
{
	int		i;
	long	long_nbr;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	long_nbr = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (ERROR);
		long_nbr = (long_nbr * 10) + str[i] - '0';
		if ((str[0] != '-' && long_nbr > INT32_MAX)
			|| (str[0] == '-' && - long_nbr < INT32_MIN))
			return (ERROR);
		i++;
	}
	if (str[0] == '-')
		long_nbr *= -1;
	*nbr = long_nbr;
	return (SUCCESS);
}

static t_status	check_duplicate_in_stack(t_stack stack, int nbr)
{
	int		i;

	i = 0;
	while (i != stack.depth)
	{
		if (stack.array[i] == nbr)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static void	change_stack_value_simply(t_stack stack)
{
	int		new_value;
	int		*current_min;
	int		i;
	int		count;

	new_value = INT32_MIN;
	count = -1;
	while (++count != stack.depth)
	{
		current_min = NULL;
		i = -1;
		while (++i != stack.depth)
		{
			if (new_value <= stack.array[i]
				&& (current_min == NULL || *current_min > stack.array[i]))
				current_min = &stack.array[i];
		}
		*current_min = new_value++;
	}
	i = -1;
	while (++i != stack.depth)
		stack.array[i] += -INT32_MIN;
}

void	init_stack(int argc, char **argv, t_stack stack[2])
{
	int		i;
	int		nbr;

	stack[A].array = (int *)malloc(sizeof(int) * argc);
	if (stack[A].array == NULL)
		exit_by_error(NULL);
	stack[B].array = (int *)malloc(sizeof(int) * argc);
	if (stack[B].array == NULL)
		exit_by_error(stack);
	stack[A].depth = 0;
	stack[B].depth = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		if (atoi_with_check(argv[i], &nbr) == ERROR
			|| check_duplicate_in_stack(stack[A], nbr) == ERROR)
			exit_by_error(stack);
		push_to_stack_bottom(&stack[A], nbr);
		i++;
	}
	change_stack_value_simply(stack[A]);
}
