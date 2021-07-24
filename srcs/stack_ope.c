/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:31:13 by mkamei            #+#    #+#             */
/*   Updated: 2021/07/24 18:48:56 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_top(t_stack *stack, int nbr)
{
	stack->top = (stack->top - 1 + stack->size) % stack->size;
	stack->array[stack->top] = nbr;
	stack->depth++;
}

void	push_to_stack_bottom(t_stack *stack, int nbr)
{
	stack->array[stack->bottom] = nbr;
	stack->bottom = (stack->bottom + 1) % stack->size;
	stack->depth++;
}

int	pop_from_stack_top(t_stack *stack)
{
	int		nbr;

	nbr = stack->array[stack->top];
	stack->top = (stack->top + 1) % stack->size;
	stack->depth--;
	return (nbr);
}

int	pop_from_stack_bottom(t_stack *stack)
{
	int		nbr;

	stack->bottom = (stack->bottom - 1 + stack->size) % stack->size;
	nbr = stack->array[stack->bottom];
	stack->depth--;
	return (nbr);
}

void	print_stack(t_stack stack[2])
{
	const char	stack_name[2][4] = {"A: ", "B: "};
	char		*nbr_str;
	int			i;
	int			j;

	i = 0;
	while (i <= 1)
	{
		write(1, stack_name[i], 3);
		j = stack[i].top;
		while (j != stack[i].bottom)
		{
			nbr_str = ft_itoa(stack[i].array[j]);
			if (nbr_str == NULL)
				return ;
			write(1, nbr_str, ft_strlen(nbr_str));
			write(1, " ", 1);
			free(nbr_str);
			j = (j + 1) % stack[i].size;
		}
		write(1, "\n", 1);
		i++;
	}
}
