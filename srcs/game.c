/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:19:14 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/25 18:14:37 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_opes(t_stack stack[2], t_stack_name name, const t_game_ope *opes)
{
	int		i;

	i = 0;
	while (opes[i] != NULL)
	{
		opes[i](stack, name);
		i++;
	}
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

static t_bool	check_sort(t_stack stack)
{
	int		i;

	i = 0;
	while (i + 1 != stack.depth)
	{
		if (stack.array[i] + 1 != stack.array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	start_game(t_stack stack[2])
{
	change_stack_value_simply(stack[A]);
	if (check_sort(stack[A]) == 1)
		return ;
	if (stack[A].depth <= 5)
		sort_less5(stack, 0, stack[A].depth - 1);
	else
		quick_sort(stack, A, 0, stack[A].depth - 1);
}

	// print_stack(stack);
