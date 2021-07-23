/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:26:50 by mkamei            #+#    #+#             */
/*   Updated: 2021/07/23 18:18:19 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_elems_in_stack(t_list *stack[2], t_stack_name swaped_stack)
{
	t_list	*first_elem;
	t_list	*second_elem;

	if (swaped_stack == A)
		write(2, "sa\n", 3);
	else
		write(2, "sb\n", 3);
	if (stack[swaped_stack] == NULL || stack[swaped_stack]->next == NULL)
		return ;
	first_elem = pop_from_stack_top(&stack[swaped_stack]);
	second_elem = pop_from_stack_top(&stack[swaped_stack]);
	push_to_stack_top(&stack[swaped_stack], first_elem);
	push_to_stack_top(&stack[swaped_stack], second_elem);
}

void	push_between_stacks(t_list *stack[2], t_stack_name pushed_stack)
{
	t_stack_name	poped_stack;
	t_list			*top_elem;

	if (pushed_stack == A)
	{
		write(1, "pa\n", 3);
		poped_stack = B;
	}
	else
	{
		write(1, "pb\n", 3);
		poped_stack = A;
	}
	if (stack[poped_stack] == NULL)
		return ;
	top_elem = pop_from_stack_top(&stack[poped_stack]);
	push_to_stack_top(&stack[pushed_stack], top_elem);
}

void	rotate_stack_to_upward(t_list *stack[2], t_stack_name rotated_stack)
{
	t_list	*top_elem;

	if (rotated_stack == A)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	if (stack[rotated_stack] == NULL || stack[rotated_stack]->next == NULL)
			return ;
	top_elem = pop_from_stack_top(&stack[rotated_stack]);
	push_to_stack_bottom(&stack[rotated_stack], top_elem);
}

void	rotate_stack_to_downward(t_list *stack[2], t_stack_name rotated_stack)
{
	t_list	*bottom_elem;

	if (rotated_stack == A)
		write(1, "rra\n", 3);
	else
		write(1, "rrb\n", 3);
	if (stack[rotated_stack] == NULL || stack[rotated_stack]->next == NULL)
			return ;
	bottom_elem = pop_from_stack_bottom(&stack[rotated_stack]);
	push_to_stack_top(&stack[rotated_stack], bottom_elem);
}
