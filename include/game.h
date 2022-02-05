/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:19:00 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/05 12:52:41 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "libft.h"
# include <stdbool.h>

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

typedef void	(*t_game_ope)(t_stack stacks[2],
					const t_stack_name name, const bool write_flag);

// init_stacks
void	init_stacks(int argc, char **argv, t_stack stacks[2]);

// game_ope
void	swap(t_stack stacks[2],
			const t_stack_name swaped_stack, const bool write_flag);
void	push(t_stack stacks[2],
			const t_stack_name pushed_stack, const bool write_flag);
void	rotate(t_stack stacks[2],
			const t_stack_name rotated_stack, const bool write_flag);
void	rrotate(t_stack stacks[2],
			const t_stack_name rrotated_stack, const bool write_flag);
void	push_and_rotate(t_stack stacks[2],
			const t_stack_name pushed_stack, const bool write_flag);

// stack_ope
void	push_to_stack_top(t_stack *stack, const int nbr);
void	push_to_stack_bottom(t_stack *stack, const int nbr);
int		pop_from_stack_top(t_stack *stack);
int		pop_from_stack_bottom(t_stack *stack);

// utils
void	free_stacks_array(const t_stack stacks[2]);
void	exit_by_error(const t_stack stacks[2]);
void	execute_game_opes(t_stack stacks[2], const t_stack_name name,
			const bool write_flag, const t_game_ope *opes);
bool	check_sort_stack(const t_stack stack);
void	print_stacks(const t_stack stacks[2]);

#endif
