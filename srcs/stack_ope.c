/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:31:13 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/24 11:56:39 by mkamei           ###   ########.fr       */
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
		j = 0;
		while (j != stack[i].depth)
		{
			nbr_str = ft_itoa(stack[i].array[j]);
			if (nbr_str == NULL)
				return ;
			write(1, nbr_str, ft_strlen(nbr_str));
			write(1, " ", 1);
			free(nbr_str);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
