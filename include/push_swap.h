/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:19:10 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/29 13:36:33 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "game.h"

typedef enum e_order{
	NORMAL	= 0,
	REVERCE	= 1
}			t_order;

// sort
void	sort_less5(t_stack stack[2], int min, int max);
void	quick_sort(t_stack stack[2], t_stack_name name, int min, int max);

#endif
