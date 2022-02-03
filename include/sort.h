/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:19:10 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/03 17:11:35 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "game.h"

# define OPE_WRITE_FLAG 1

typedef enum e_order{
	NORMAL	= 0,
	REVERSE	= 1
}			t_order;

// sort
void	sort_less5(t_stack stack[2], int min, int max);
void	quick_sort(t_stack stack[2], t_stack_name name, int min, int max);

#endif
