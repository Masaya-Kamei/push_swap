/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:19:10 by mkamei            #+#    #+#             */
/*   Updated: 2021/07/24 18:47:43 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <stdio.h>

typedef enum e_status{
	SUCCESS	= 0,
	ERROR	= 1
}			t_status;

typedef enum e_stack_name{
	A	= 0,
	B	= 1
}			t_stack_name;

typedef struct s_stack{
	int		*array;
	int		top;
	int		bottom;
	int		depth;
	int		size;
}			t_stack;

void	swap_top_elems_in_stack(t_stack stack[2], t_stack_name swaped_stack);
void	push_between_stacks(t_stack stack[2], t_stack_name pushed_stack);
void	rotate_stack_to_upward(t_stack stack[2], t_stack_name rotated_stack);
void	rotate_stack_to_downward(t_stack stack[2], t_stack_name rotated_stack);
void	push_to_stack_top(t_stack *stack, int nbr);
void	push_to_stack_bottom(t_stack *stack, int nbr);
int		pop_from_stack_top(t_stack *stack);
int		pop_from_stack_bottom(t_stack *stack);
void	print_stack(t_stack stack[2]);

#endif
