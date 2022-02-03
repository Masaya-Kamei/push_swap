/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5or_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:54:51 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/03 17:12:13 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

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
		execute_game_opes(stack, A, OPE_WRITE_FLAG, opes_len3[f]);
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
