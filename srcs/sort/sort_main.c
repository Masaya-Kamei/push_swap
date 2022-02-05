/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:24:41 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/05 13:17:55 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	main(int argc, char **argv)
{
	t_stack	stacks[2];

	if (argc <= 1)
		return (0);
	init_stacks(argc, argv, stacks);
	if (check_sort_stack(stacks[A]) == 1)
	{
		free_stacks_array(stacks);
		return (0);
	}
	if (stacks[A].depth <= 5)
		sort_5or_less(stacks, 0, stacks[A].depth - 1);
	else
		quick_sort_6or_more(stacks, A, 0, stacks[A].depth - 1);
	free_stacks_array(stacks);
	return (0);
}
