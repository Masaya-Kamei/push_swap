/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:24:41 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/28 18:49:14 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_stack	stack[2];

	if (argc <= 1)
		return (0);
	init_stack(argc, argv, stack);
	if (check_sort(stack[A]) == 1)
		return (0);
	if (stack[A].depth <= 5)
		sort_less5(stack, 0, stack[A].depth - 1);
	else
		quick_sort(stack, A, 0, stack[A].depth - 1);
	free(stack[A].array);
	free(stack[B].array);
	return (0);
}

	// print_stack(stack);
