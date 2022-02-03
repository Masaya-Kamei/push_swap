/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:24:41 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/03 17:12:26 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	main(int argc, char **argv)
{
	t_stack	stack[2];

	if (argc <= 1)
		return (0);
	init_stack(argc, argv, stack);
	if (check_sort(stack[A]) == 1)
	{
		free(stack[A].array);
		free(stack[B].array);
		return (0);
	}
	if (stack[A].depth <= 5)
		sort_less5(stack, 0, stack[A].depth - 1);
	else
		quick_sort(stack, A, 0, stack[A].depth - 1);
	free(stack[A].array);
	free(stack[B].array);
	return (0);
}

	// print_stack(stack);
