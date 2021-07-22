/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:19:10 by mkamei            #+#    #+#             */
/*   Updated: 2021/07/22 13:11:57 by mkamei           ###   ########.fr       */
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

typedef enum e_stack_name
{
	A	= 0,
	B	= 1
}			t_stack_name;

void	print_stack(t_list *stack[2]);

#endif
