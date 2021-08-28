/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:31:13 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/28 18:25:13 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_top(t_stack *stack, int nbr)
{
	int		i;

	i = stack->depth;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = nbr;
	stack->depth++;
}

void	push_to_stack_bottom(t_stack *stack, int nbr)
{
	stack->array[stack->depth] = nbr;
	stack->depth++;
}

int	pop_from_stack_top(t_stack *stack)
{
	int		nbr;
	int		i;

	nbr = stack->array[0];
	stack->depth--;
	i = 0;
	while (i < stack->depth)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	return (nbr);
}

int	pop_from_stack_bottom(t_stack *stack)
{
	int		nbr;

	nbr = stack->array[stack->depth - 1];
	stack->depth--;
	return (nbr);
}

t_bool	check_sort(t_stack stack)
{
	int		i;

	i = 0;
	while (i + 1 != stack.depth)
	{
		if (stack.array[i] + 1 != stack.array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
