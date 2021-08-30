/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:48:08 by mkamei            #+#    #+#             */
/*   Updated: 2021/08/30 13:39:43 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	read_until_newline(char buf[BUFFERSIZE])
{
	char	c;
	int		readsize;
	int		read_status;

	readsize = read(0, buf, BUFFERSIZE - 4);
	if (readsize <= 0)
		return (readsize);
	while (buf[readsize - 1] != '\n')
	{
		read_status = read(0, &c, 1);
		if (read_status <= 0)
			return (-1);
		buf[readsize] = c;
		if (readsize == BUFFERSIZE - 1)
			return (-1);
		readsize++;
	}
	return (readsize);
}

static t_status	exec_ope_strs(t_stack stack[2], char **ope_strs)
{
	int					i;
	int					j;
	const char			ope_names[11][4]
		= {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	const t_game_ope	ope_funcs[11]
		= {swap, swap, swap, push, push,
			rotate, rotate, rotate, rrotate, rrotate, rrotate};
	const t_stack_name	second_args[11] = {A, B, AB, A, B, A, B, AB, A, B, AB};

	i = -1;
	while (ope_strs[++i] != NULL)
	{
		j = -1;
		while (++j < 11)
		{
			if (ft_strncmp(ope_strs[i], ope_names[j], 4) == 0)
			{
				ope_funcs[j](stack, second_args[j], OPE_WRITE_FLAG);
				break ;
			}
		}
		if (j == 11)
			return (ERROR);
	}
	return (SUCCESS);
}

static void	free_double_pointer(char **strs)
{
	int		i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	receive_game_opes(t_stack stack[2])
{
	int			readsize;
	char		buf[BUFFERSIZE];
	char		**ope_strs;
	t_status	status;

	readsize = read_until_newline(buf);
	if (readsize <= 0)
		exit_by_error(stack);
	while (readsize != 0)
	{
		if (readsize == -1)
			exit_by_error(stack);
		buf[readsize] = '\0';
		ope_strs = ft_split(buf, '\n');
		if (ope_strs == NULL)
			exit_by_error(stack);
		status = exec_ope_strs(stack, ope_strs);
		free_double_pointer(ope_strs);
		if (status == ERROR)
			exit_by_error(stack);
		readsize = read_until_newline(buf);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack[2];

	if (argc <= 1)
		return (0);
	init_stack(argc, argv, stack);
	receive_game_opes(stack);
	if (check_sort(stack[A]) == 1 && stack[B].depth == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack[A].array);
	free(stack[B].array);
	return (0);
}
