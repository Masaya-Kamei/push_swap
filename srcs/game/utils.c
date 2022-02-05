/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:33:31 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/05 12:46:33 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	free_stacks_array(const t_stack stacks[2])
{
	free(stacks[A].array);
	free(stacks[B].array);
}

void	exit_by_error(const t_stack stacks[2])
{
	if (stacks)
		free_stacks_array(stacks);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

void	execute_game_opes(t_stack stacks[2],
	const t_stack_name name, const bool write_flag, const t_game_ope *opes)
{
	int		i;

	i = 0;
	while (opes[i])
	{
		opes[i](stacks, name, write_flag);
		i++;
	}
}

bool	check_sort_stack(const t_stack stack)
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

void	print_stacks(const t_stack stacks[2])
{
	const char	stack_names[2][4] = {"A: ", "B: "};
	char		*nbr_str;
	int			i;
	int			j;

	i = 0;
	while (i <= 1)
	{
		write(STDOUT_FILENO, stack_names[i], 3);
		j = 0;
		while (j != stacks[i].depth)
		{
			nbr_str = ft_itoa(stacks[i].array[j]);
			if (nbr_str == NULL)
				return ;
			write(STDOUT_FILENO, nbr_str, ft_strlen(nbr_str));
			write(STDOUT_FILENO, " ", 1);
			free(nbr_str);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
