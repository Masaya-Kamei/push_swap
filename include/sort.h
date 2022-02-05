/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:19:10 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/05 11:39:09 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "game.h"

typedef enum e_order{
	NORMAL	= 0,
	REVERSE	= 1
}			t_order;

// sort
void	sort_5or_less(t_stack stack[2], const int min, const int max);
void	quick_sort_6or_more(t_stack stack[2],
			const t_stack_name name, int min, const int max);

#endif
