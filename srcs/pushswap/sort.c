/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:44:22 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/30 13:35:23 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less5(t_stack stack[2], int min, int max)
{
	const int			len = max - min + 1;
	int					f;
	t_game_ope			ope;
	const t_game_ope	opes_len3[6][3]
		= {{NULL}, {rrotate, swap, NULL}, {swap, NULL}
		, {rrotate, NULL}, {rotate, NULL}, {rotate, swap, NULL}};

	if (len == 2)
		return (swap(stack, A, OPE_WRITE_FLAG));
	else if (len == 3)
	{
		f = ((stack[A].array[0] * 2) + (stack[A].array[1] > stack[A].array[2]));
		exec_opes(stack, A, opes_len3[f], OPE_WRITE_FLAG);
		while (stack[B].depth > 0)
			push_and_rotate(stack, A, OPE_WRITE_FLAG);
		return ;
	}
	if (stack[A].array[3] == max || (len == 5 && stack[A].array[4] == max))
		ope = rrotate;
	else
		ope = rotate;
	while (stack[A].array[0] != max)
		ope(stack, A, OPE_WRITE_FLAG);
	push(stack, B, OPE_WRITE_FLAG);
	sort_less5(stack, min, max - 1);
}

static void	bubble_sort_less4(
	t_stack stack[2], t_stack_name name, int min, int max)
{
	const int			len = max - min + 1;
	const t_game_ope	opes1[5]
		= {rotate, swap, rrotate, swap, NULL};
	const t_game_ope	opes2[8]
		= {rotate, rotate, swap, rrotate, swap, rrotate, swap, NULL};

	if (len == 0)
		return ;
	else if (len >= 2 && stack[name].array[1] == min)
		swap(stack, name, OPE_WRITE_FLAG);
	else if (len >= 3 && stack[name].array[2] == min)
		exec_opes(stack, name, opes1, OPE_WRITE_FLAG);
	else if (len == 4 && stack[name].array[3] == min)
		exec_opes(stack, name, opes2, OPE_WRITE_FLAG);
	if (name == B)
		push(stack, A, OPE_WRITE_FLAG);
	rotate(stack, A, OPE_WRITE_FLAG);
	bubble_sort_less4(stack, name, min + 1, max);
}

static int	count_rised_num_from_min(
	t_stack stack, t_order order, int min, int max)
{
	int		i;
	int		value;
	int		count;
	int		len;

	if (order == NORMAL)
		i = 0;
	else
		i = stack.depth - 1;
	if (order == NORMAL)
		value = 1;
	else
		value = -1;
	count = 0;
	len = max - min + 1;
	while (--len >= 0)
	{
		if (stack.array[i] == min)
		{
			count++;
			min++;
		}
		i += value;
	}
	return (count);
}

static void	reverce_quick_sort(
	t_stack stack[2], t_stack_name name, int min, int max)
{
	int		len;
	int		others_len;
	int		median;

	len = max - min + 1;
	others_len = stack[name].depth - len;
	if (others_len < len)
	{
		while (--others_len >= 0)
			rotate(stack, name, OPE_WRITE_FLAG);
		return (quick_sort(stack, name, min, max));
	}
	if (name == B)
		min += count_rised_num_from_min(stack[B], REVERCE, min, max);
	median = (min + max) / 2;
	while (--len >= 0)
	{
		rrotate(stack, name, OPE_WRITE_FLAG);
		if (median < stack[name].array[0])
			push(stack, (name + 1) % 2, OPE_WRITE_FLAG);
		else if (name == B && stack[name].array[0] < min)
			push_and_rotate(stack, A, OPE_WRITE_FLAG);
	}
	quick_sort(stack, name, min, median);
	quick_sort(stack, (name + 1) % 2, median + 1, max);
}

void	quick_sort(t_stack stack[2], t_stack_name name, int min, int max)
{
	int		len;
	int		median;

	len = max - min + 1;
	if (len <= 4)
		return (bubble_sort_less4(stack, name, min, max));
	if (name == B)
		min += count_rised_num_from_min(stack[B], NORMAL, min, max);
	median = (min + max) / 2;
	while (--len >= 0)
	{
		if (median < stack[name].array[0])
			push(stack, (name + 1) % 2, OPE_WRITE_FLAG);
		else if (name == B && stack[name].array[0] < min)
			push_and_rotate(stack, A, OPE_WRITE_FLAG);
		else
			rotate(stack, name, OPE_WRITE_FLAG);
	}
	reverce_quick_sort(stack, name, min, median);
	quick_sort(stack, (name + 1) % 2, median + 1, max);
}
