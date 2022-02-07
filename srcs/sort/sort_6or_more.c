/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6or_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:44:22 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/07 14:29:45 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	bubble_sort_4or_less(
	t_stack stacks[2], const t_stack_name name, const int min, const int max)
{
	const int			len = max - min + 1;
	const t_game_ope	opes_min3[5]
		= {rotate, swap, rrotate, swap, NULL};
	const t_game_ope	opes_min4[8]
		= {rotate, rotate, swap, rrotate, swap, rrotate, swap, NULL};

	if (len <= 0)
		return ;
	else if (len >= 2 && stacks[name].array[1] == min)
		swap(stacks, name, true);
	else if (len >= 3 && stacks[name].array[2] == min)
		execute_game_opes(stacks, name, true, opes_min3);
	else if (len == 4 && stacks[name].array[3] == min)
		execute_game_opes(stacks, name, true, opes_min4);
	if (name == B)
		push(stacks, A, true);
	rotate(stacks, A, true);
	bubble_sort_4or_less(stacks, name, min + 1, max);
}

static void	rev_sort_4or_less(
	t_stack stacks[2], const t_stack_name name, const int min, const int max)
{
	int			len;
	const int	bottom = stacks[name].depth - 1;
	int			min_count;

	len = max - min + 1;
	if (len <= 0)
		return ;
	if (name == A && min == stacks[A].array[bottom - len + 1])
		return (rev_sort_4or_less(stacks, A, min + 1, max));
	min_count = 0;
	while (--len >= 0)
	{
		rrotate(stacks, name, true);
		if (name == B && stacks[B].array[0] == min + min_count)
		{
			push_and_rotate(stacks, A, true);
			min_count++;
		}
	}
	bubble_sort_4or_less(stacks, name, min + min_count, max);
}

static int	count_rised_num_from_min(
	t_stack stack, const t_order order, const int min, const int max)
{
	int		i;
	int		inc;
	int		min_count;
	int		len;

	if (order == NORMAL)
	{
		i = 0;
		inc = 1;
	}
	else
	{
		i = stack.depth - 1;
		inc = -1;
	}
	min_count = 0;
	len = max - min + 1;
	while (--len >= 0)
	{
		if (stack.array[i] == min + min_count)
			min_count++;
		i += inc;
	}
	return (min_count);
}

static void	rev_quick_sort_6or_more(
	t_stack stacks[2], const t_stack_name name, int min, const int max)
{
	int		len;
	int		median;

	len = max - min + 1;
	if (stacks[name].depth == len)
		return (quick_sort_6or_more(stacks, name, min, max));
	if (len <= 4)
		return (rev_sort_4or_less(stacks, name, min, max));
	if (name == B)
		min += count_rised_num_from_min(stacks[B], REVERSE, min, max);
	median = (min + max) / 2;
	while (--len >= 0)
	{
		rrotate(stacks, name, true);
		if (name == B && stacks[name].array[0] < min)
			push_and_rotate(stacks, A, true);
		else if (median < stacks[name].array[0])
			push(stacks, (name + 1) % 2, true);
	}
	quick_sort_6or_more(stacks, name, min, median);
	quick_sort_6or_more(stacks, (name + 1) % 2, median + 1, max);
}

void	quick_sort_6or_more(
	t_stack stacks[2], const t_stack_name name, int min, const int max)
{
	int		len;
	int		median;

	len = max - min + 1;
	if (len <= 4)
		return (bubble_sort_4or_less(stacks, name, min, max));
	if (name == B)
		min += count_rised_num_from_min(stacks[B], NORMAL, min, max);
	median = (min + max) / 2;
	while (--len >= 0)
	{
		if (name == B && stacks[B].array[0] < min)
			push_and_rotate(stacks, A, true);
		else if (median < stacks[name].array[0])
			push(stacks, (name + 1) % 2, true);
		else
			rotate(stacks, name, true);
	}
	rev_quick_sort_6or_more(stacks, name, min, median);
	quick_sort_6or_more(stacks, (name + 1) % 2, median + 1, max);
}
