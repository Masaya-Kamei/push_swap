/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:22:17 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/28 18:46:56 by mkamei           ###   ########.fr       */
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

void	sort_less5(t_stack stack[2], int min, int max)
{
	const int			len = max - min + 1;
	int					f;
	t_game_ope			ope;
	const t_game_ope	opes_len3[6][3]
		= {{NULL}, {rrotate, swap, NULL}, {swap, NULL}
		, {rrotate, NULL}, {rotate, NULL}, {rotate, swap, NULL}};

	if (len == 2)
		return (swap(stack, A));
	else if (len == 3)
	{
		f = ((stack[A].array[0] * 2) + (stack[A].array[1] > stack[A].array[2]));
		exec_opes(stack, A, opes_len3[f]);
		while (stack[B].depth > 0)
			push_and_rotate(stack, A);
		return ;
	}
	if (stack[A].array[3] == max || (len == 5 && stack[A].array[4] == max))
		ope = rrotate;
	else
		ope = rotate;
	while (stack[A].array[0] != max)
		ope(stack, A);
	push(stack, B);
	sort_less5(stack, min, max - 1);
}
