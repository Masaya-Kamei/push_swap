/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:26:50 by mkamei            #+#    #+#             */
/*   Updated: 2021/07/24 18:50:10 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_elems_in_stack(t_stack stack[2], t_stack_name swaped_stack)
{
	const char	ope_name[2][4] = {"sa\n", "sb\n"};
	int			nbr1;
	int			nbr2;

	write(1, ope_name[swaped_stack], 3);
	if (stack[swaped_stack].depth <= 1)
		return ;
	nbr1 = pop_from_stack_top(&stack[swaped_stack]);
	nbr2 = pop_from_stack_top(&stack[swaped_stack]);
	push_to_stack_top(&stack[swaped_stack], nbr1);
	push_to_stack_top(&stack[swaped_stack], nbr2);
}

void	push_between_stacks(t_stack stack[2], t_stack_name pushed_stack)
{
	const char			ope_name[2][4] = {"pa\n", "pb\n"};
	const t_stack_name	poped_stack = (pushed_stack + 1) % 2;
	int					nbr;

	write(1, ope_name[pushed_stack], 3);
	if (stack[poped_stack].depth == 0)
		return ;
	nbr = pop_from_stack_top(&stack[poped_stack]);
	push_to_stack_top(&stack[pushed_stack], nbr);
}

void	rotate_stack_to_upward(t_stack stack[2], t_stack_name rotated_stack)
{
	const char	ope_name[2][4] = {"ra\n", "rb\n"};
	int			nbr;

	write(1, ope_name[rotated_stack], 3);
	if (stack[rotated_stack].depth <= 1)
		return ;
	nbr = pop_from_stack_top(&stack[rotated_stack]);
	push_to_stack_bottom(&stack[rotated_stack], nbr);
}

void	rotate_stack_to_downward(t_stack stack[2], t_stack_name rotated_stack)
{
	const char	ope_name[2][5] = {"rra\n", "rrb\n"};
	int			nbr;

	write(1, ope_name[rotated_stack], 4);
	if (stack[rotated_stack].depth <= 1)
		return ;
	nbr = pop_from_stack_bottom(&stack[rotated_stack]);
	push_to_stack_top(&stack[rotated_stack], nbr);
}
