/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:26:50 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/05 12:42:09 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	swap(t_stack stacks[2],
	const t_stack_name swaped_stack, const bool write_flag)
{
	const char	ope_names[3][4] = {"sa\n", "sb\n", "ss\n"};
	int			nbr1;
	int			nbr2;

	if (write_flag)
		write(STDOUT_FILENO, ope_names[swaped_stack], 3);
	if ((swaped_stack == A || swaped_stack == AB) && stacks[A].depth >= 2)
	{
		nbr1 = pop_from_stack_top(&stacks[A]);
		nbr2 = pop_from_stack_top(&stacks[A]);
		push_to_stack_top(&stacks[A], nbr1);
		push_to_stack_top(&stacks[A], nbr2);
	}
	if ((swaped_stack == B || swaped_stack == AB) && stacks[B].depth >= 2)
	{
		nbr1 = pop_from_stack_top(&stacks[B]);
		nbr2 = pop_from_stack_top(&stacks[B]);
		push_to_stack_top(&stacks[B], nbr1);
		push_to_stack_top(&stacks[B], nbr2);
	}
}

void	push(t_stack stacks[2],
	const t_stack_name pushed_stack, const bool write_flag)
{
	const char			ope_names[2][4] = {"pa\n", "pb\n"};
	const t_stack_name	poped_stack = (pushed_stack + 1) % 2;
	int					nbr;

	if (write_flag)
		write(STDOUT_FILENO, ope_names[pushed_stack], 3);
	if (stacks[poped_stack].depth >= 1)
	{
		nbr = pop_from_stack_top(&stacks[poped_stack]);
		push_to_stack_top(&stacks[pushed_stack], nbr);
	}
}

void	rotate(t_stack stacks[2],
	const t_stack_name rotated_stack, const bool write_flag)
{
	const char	ope_names[3][4] = {"ra\n", "rb\n", "rr\n"};
	int			nbr;

	if (write_flag)
		write(STDOUT_FILENO, ope_names[rotated_stack], 3);
	if ((rotated_stack == A || rotated_stack == AB) && stacks[A].depth >= 2)
	{
		nbr = pop_from_stack_top(&stacks[A]);
		push_to_stack_bottom(&stacks[A], nbr);
	}
	if ((rotated_stack == B || rotated_stack == AB) && stacks[B].depth >= 2)
	{
		nbr = pop_from_stack_top(&stacks[B]);
		push_to_stack_bottom(&stacks[B], nbr);
	}
}

void	rrotate(t_stack stacks[2],
	const t_stack_name rrotated_stack, const bool write_flag)
{
	const char	ope_names[3][5] = {"rra\n", "rrb\n", "rrr\n"};
	int			nbr;

	if (write_flag)
		write(STDOUT_FILENO, ope_names[rrotated_stack], 4);
	if ((rrotated_stack == A || rrotated_stack == AB) && stacks[A].depth >= 2)
	{
		nbr = pop_from_stack_bottom(&stacks[A]);
		push_to_stack_top(&stacks[A], nbr);
	}
	if ((rrotated_stack == B || rrotated_stack == AB) && stacks[B].depth >= 2)
	{
		nbr = pop_from_stack_bottom(&stacks[B]);
		push_to_stack_top(&stacks[B], nbr);
	}
}

void	push_and_rotate(t_stack stacks[2],
	const t_stack_name pushed_stack, const bool write_flag)
{
	push(stacks, pushed_stack, write_flag);
	rotate(stacks, pushed_stack, write_flag);
}
