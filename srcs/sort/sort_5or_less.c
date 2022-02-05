/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5or_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:54:51 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/05 13:15:45 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	push_max_to_stack_b(t_stack stacks[2], const int max, const int len)
{
	t_game_ope	ope;

	if (stacks[A].array[3] == max || (len == 5 && stacks[A].array[4] == max))
		ope = rrotate;
	else
		ope = rotate;
	while (stacks[A].array[0] != max)
		ope(stacks, A, true);
	push(stacks, B, true);
}

void	sort_5or_less(t_stack stacks[2], const int min, const int max)
{
	const int			len = max - min + 1;
	int					i;
	const t_game_ope	opes_len3[6][3]
		= {{NULL}, {rrotate, swap, NULL}, {swap, NULL}
		, {rrotate, NULL}, {rotate, NULL}, {rotate, swap, NULL}};

	if (len == 2)
		swap(stacks, A, true);
	else if (len == 3)
	{
		i = ((stacks[A].array[0] * 2)
				+ (stacks[A].array[1] > stacks[A].array[2]));
		execute_game_opes(stacks, A, true, opes_len3[i]);
		while (stacks[B].depth > 0)
			push_and_rotate(stacks, A, true);
	}
	else
	{
		push_max_to_stack_b(stacks, max, len);
		sort_5or_less(stacks, min, max - 1);
	}
}
