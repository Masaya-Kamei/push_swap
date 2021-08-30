/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:19:00 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/30 13:41:24 by mkamei           ###   ########.fr       */
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

typedef void	(*t_game_ope)(
					t_stack stack[2], t_stack_name name, t_bool write_flag);

// init_stack
void	init_stack(int argc, char **argv, t_stack stack[2]);

// game_ope
void	swap(t_stack stack[2], t_stack_name swaped_stack, t_bool write_flag);
void	push(t_stack stack[2], t_stack_name pushed_stack, t_bool write_flag);
void	rotate(t_stack stack[2], t_stack_name rotated_stack, t_bool write_flag);
void	rrotate(
			t_stack stack[2], t_stack_name rrotated_stack, t_bool write_flag);
void	push_and_rotate(
			t_stack stack[2], t_stack_name pushed_stack, t_bool write_flag);

// stack_ope
void	push_to_stack_top(t_stack *stack, int nbr);
void	push_to_stack_bottom(t_stack *stack, int nbr);
int		pop_from_stack_top(t_stack *stack);
int		pop_from_stack_bottom(t_stack *stack);

// utils
void	exit_by_error(t_stack stack[2]);
void	execute_game_opes(t_stack stack[2],
			t_stack_name name, t_bool write_flag, const t_game_ope *opes);
t_bool	check_sort(t_stack stack);
void	print_stack(t_stack stack[2]);

#endif
