/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:19:10 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/25 18:13:42 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef enum e_bool{
	FALSE	= 0,
	TRUE	= 1
}			t_bool;

typedef enum e_order{
	NORMAL	= 0,
	REVERCE	= 1
}			t_order;

typedef enum e_status{
	SUCCESS	= 0,
	ERROR	= 1
}			t_status;

typedef enum e_stack_name{
	A	= 0,
	B	= 1,
	AB	= 2
}			t_stack_name;

typedef struct s_stack{
	int		*array;
	int		depth;
}			t_stack;

typedef void	(*t_game_ope)(t_stack stack[2], t_stack_name name);

// main
void	start_game(t_stack stack[2]);
void	sort_less5(t_stack stack[2], int min, int max);
void	quick_sort(t_stack stack[2], t_stack_name name, int min, int max);
void	exec_opes(t_stack stack[2], t_stack_name name, const t_game_ope *opes);

// game_ope
void	swap(t_stack stack[2], t_stack_name swaped_stack);
void	push(t_stack stack[2], t_stack_name pushed_stack);
void	rotate(t_stack stack[2], t_stack_name rotated_stack);
void	rrotate(t_stack stack[2], t_stack_name rotated_stack);
void	push_and_rotate(t_stack stack[2], t_stack_name pushed_stack);

// stack_ope
void	push_to_stack_top(t_stack *stack, int nbr);
void	push_to_stack_bottom(t_stack *stack, int nbr);
int		pop_from_stack_top(t_stack *stack);
int		pop_from_stack_bottom(t_stack *stack);
void	print_stack(t_stack stack[2]);

#endif
