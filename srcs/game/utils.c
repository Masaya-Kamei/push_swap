/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:33:31 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/30 13:41:42 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	exit_by_error(t_stack stack[2])
{
	if (stack != NULL)
	{
		free(stack[A].array);
		free(stack[B].array);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	execute_game_opes(t_stack stack[2],
	t_stack_name name, t_bool write_flag, const t_game_ope *opes)
{
	int		i;

	i = 0;
	while (opes[i] != NULL)
	{
		opes[i](stack, name, write_flag);
		i++;
	}
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
