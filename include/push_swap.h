/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:19:10 by mkamei            #+#    #+#             */
/*   Updated: 2021/07/23 18:17:02 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <stdio.h>

typedef enum e_rotate_direction
{
	UP		= 0,
	DOWN	= 1
}			t_rotate_direction;

typedef enum e_status{
	SUCCESS	= 0,
	ERROR	= 1
}			t_status;

typedef enum e_stack_name
{
	A	= 0,
	B	= 1
}			t_stack_name;

void	swap_top_two_elem_in_stack(t_list *stack[2], t_stack_name swaped_stack);
void	push_between_stacks(t_list *stack[2], t_stack_name pushed_stack);
void	rotate_stack_to_upward(t_list *stack[2], t_stack_name rotated_stack);
void	rotate_stack_to_downward(t_list *stack[2], t_stack_name rotated_stack);
void	push_to_stack_top(t_list **any_stack, t_list *new_list);
void	push_to_stack_bottom(t_list **any_stack, t_list *new_list);
t_list	*pop_from_stack_top(t_list **any_stack);
t_list	*pop_from_stack_bottom(t_list **any_stack);
void	print_stack(t_list *stack[2]);

#endif
