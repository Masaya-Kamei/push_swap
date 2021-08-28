/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:19:00 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/28 18:33:07 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "libft.h"

typedef enum e_bool{
	FALSE	= 0,
	TRUE	= 1
}			t_bool;

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

// init_stack
void	init_stack(int argc, char **argv, t_stack stack[2]);

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
t_bool	check_sort(t_stack stack);

#endif
