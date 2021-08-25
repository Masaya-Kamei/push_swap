/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:24:41 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/25 17:58:11 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_status	atoi_with_check(char *str, int *nbr)
{
	int		i;
	long	long_nbr;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	long_nbr = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (ERROR);
		long_nbr = (long_nbr * 10) + str[i] - '0';
		if ((str[0] != '-' && long_nbr > INT32_MAX)
			|| (str[0] == '-' && - long_nbr < INT32_MIN))
			return (ERROR);
		i++;
	}
	if (str[0] == '-')
		long_nbr *= -1;
	*nbr = long_nbr;
	return (SUCCESS);
}

static t_status	check_duplicate_in_stack(t_stack stack, int nbr)
{
	int		i;

	i = 0;
	while (i != stack.depth)
	{
		if (stack.array[i] == nbr)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static void	exit_by_error(t_stack stack[2])
{
	if (stack != NULL)
	{
		free(stack[A].array);
		free(stack[B].array);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		nbr;
	t_stack	stack[2];

	if (argc <= 1)
		return (0);
	stack[A].array = (int *)malloc(sizeof(int) * argc);
	if (stack[A].array == NULL)
		exit_by_error(NULL);
	stack[B].array = (int *)malloc(sizeof(int) * argc);
	if (stack[B].array == NULL)
		exit_by_error(stack);
	stack[A].depth = 0;
	stack[B].depth = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		if (atoi_with_check(argv[i], &nbr) == ERROR
			|| check_duplicate_in_stack(stack[A], nbr) == ERROR)
			exit_by_error(stack);
		push_to_stack_bottom(&stack[A], nbr);
		i++;
	}
	start_game(stack);
	return (0);
}
