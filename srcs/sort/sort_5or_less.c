/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5or_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:54:51 by mkamei            #+#    #+#             */
/*   Updated: 2022/03/25 09:14:01 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	push_max_to_stack_b(t_stack stacks[2], const int max)
{
	t_game_ope	ope;

	if ((stacks[A].depth >= 4 && stacks[A].array[3] == max)
		|| (stacks[A].depth >= 5 && stacks[A].array[4] == max))
		ope = rrotate;
	else
		ope = rotate;
	while (stacks[A].array[0] != max)
		ope(stacks, A, true);
	push(stacks, B, true);
}

static void	sort_2(t_stack stacks[2], const int min)
{
	if (stacks[A].array[1] == min)
		swap(stacks, A, true);
}

static void	sort_3(t_stack stacks[2], const int min)
{
	int					i;
	const t_game_ope	opes_len3[6][3]
		= {{NULL}, {rrotate, swap, NULL}, {swap, NULL}
		, {rrotate, NULL}, {rotate, NULL}, {rotate, swap, NULL}};

	i = (stacks[A].array[0] - min) * 2;
	i += (stacks[A].array[1] > stacks[A].array[2]);
	execute_game_opes(stacks, A, true, opes_len3[i]);
}

void	sort_5or_less(t_stack stacks[2], const int min, const int max)
{
	const int	len = max - min + 1;
	int			pushed_count;

	if (len == 1)
		return ;
	else if (len == 2)
		return (sort_2(stacks, min));
	pushed_count = 0;
	while (len - pushed_count >= 4)
		push_max_to_stack_b(stacks, max - pushed_count++);
	sort_3(stacks, min);
	while (--pushed_count >= 0)
		push_and_rotate(stacks, A, true);
}
