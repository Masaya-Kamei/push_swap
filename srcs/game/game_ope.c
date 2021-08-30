/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:26:50 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/30 13:30:22 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	swap(t_stack stack[2], t_stack_name swaped_stack, t_bool write_flag)
{
	const char	ope_name[3][4] = {"sa\n", "sb\n", "ss\n"};
	int			nbr1;
	int			nbr2;

	if (write_flag == 1)
		write(1, ope_name[swaped_stack], 3);
	if (swaped_stack == A || swaped_stack == AB)
	{
		nbr1 = pop_from_stack_top(&stack[A]);
		nbr2 = pop_from_stack_top(&stack[A]);
		push_to_stack_top(&stack[A], nbr1);
		push_to_stack_top(&stack[A], nbr2);
	}
	if (swaped_stack == B || swaped_stack == AB)
	{
		nbr1 = pop_from_stack_top(&stack[B]);
		nbr2 = pop_from_stack_top(&stack[B]);
		push_to_stack_top(&stack[B], nbr1);
		push_to_stack_top(&stack[B], nbr2);
	}
}

void	push(t_stack stack[2], t_stack_name pushed_stack, t_bool write_flag)
{
	const char			ope_name[2][4] = {"pa\n", "pb\n"};
	const t_stack_name	poped_stack = (pushed_stack + 1) % 2;
	int					nbr;

	if (write_flag == 1)
		write(1, ope_name[pushed_stack], 3);
	nbr = pop_from_stack_top(&stack[poped_stack]);
	push_to_stack_top(&stack[pushed_stack], nbr);
}

void	rotate(t_stack stack[2], t_stack_name rotated_stack, t_bool write_flag)
{
	const char	ope_name[3][4] = {"ra\n", "rb\n", "rr\n"};
	int			nbr;

	if (write_flag == 1)
		write(1, ope_name[rotated_stack], 3);
	if (rotated_stack == A || rotated_stack == AB)
	{
		nbr = pop_from_stack_top(&stack[A]);
		push_to_stack_bottom(&stack[A], nbr);
	}
	if (rotated_stack == B || rotated_stack == AB)
	{
		nbr = pop_from_stack_top(&stack[B]);
		push_to_stack_bottom(&stack[B], nbr);
	}
}

void	rrotate(
	t_stack stack[2], t_stack_name rrotated_stack, t_bool write_flag)
{
	const char	ope_name[3][5] = {"rra\n", "rrb\n", "rrr\n"};
	int			nbr;

	if (write_flag == 1)
		write(1, ope_name[rrotated_stack], 4);
	if (rrotated_stack == A || rrotated_stack == AB)
	{
		nbr = pop_from_stack_bottom(&stack[A]);
		push_to_stack_top(&stack[A], nbr);
	}
	if (rrotated_stack == B || rrotated_stack == AB)
	{
		nbr = pop_from_stack_bottom(&stack[B]);
		push_to_stack_top(&stack[B], nbr);
	}
}

void	push_and_rotate(
	t_stack stack[2], t_stack_name pushed_stack, t_bool write_flag)
{
	push(stack, pushed_stack, write_flag);
	rotate(stack, pushed_stack, write_flag);
}
