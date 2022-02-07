/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:48:08 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/07 13:46:12 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	read_until_newline(char *buf)
{
	int		readsize;
	int		read_status;

	readsize = 0;
	while (1)
	{
		read_status = read(STDIN_FILENO, &buf[readsize], 1);
		if (read_status <= 0)
			return (-1);
		readsize++;
		if (buf[readsize - 1] == '\n')
			return (readsize);
		else if (readsize == 3)
			return (-1);
	}
}

static t_status	execute_game_ope_strs(t_stack stacks[2], char **ope_strs)
{
	int					i;
	int					j;
	const char			ope_names[11][4]
		= {"sa", "sb", "ss", "ra", "rb", "rr", "rra", "rrb", "rrr", "pa", "pb"};
	const t_game_ope	ope_funcs[4] = {swap, rotate, rrotate, push};
	const t_stack_name	second_args[3] = {A, B, AB};

	i = -1;
	while (ope_strs[++i])
	{
		j = -1;
		while (++j < 11)
		{
			if (ft_strncmp(ope_strs[i], ope_names[j], 4) == 0)
			{
				ope_funcs[j / 3](stacks, second_args[j % 3], false);
				break ;
			}
		}
		if (j == 11)
			return (ERROR);
	}
	if (i == 0)
		return (ERROR);
	return (SUCCESS);
}

static void	free_double_ptr(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	receive_game_opes(t_stack stacks[2])
{
	int			readsize;
	char		buf[BUFFERSIZE];
	char		**ope_strs;
	t_status	status;

	readsize = read(STDIN_FILENO, buf, BUFFERSIZE - 4);
	while (readsize != 0)
	{
		if (readsize == -1)
			exit_by_error(stacks);
		if (buf[readsize - 1] != '\n')
			readsize += read_until_newline(&buf[readsize]);
		buf[readsize] = '\0';
		ope_strs = ft_split(buf, '\n');
		if (ope_strs == NULL)
			exit_by_error(stacks);
		status = execute_game_ope_strs(stacks, ope_strs);
		free_double_ptr(ope_strs);
		if (status == ERROR)
			exit_by_error(stacks);
		readsize = read(STDIN_FILENO, buf, BUFFERSIZE - 4);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stacks[2];

	if (argc <= 1)
		return (0);
	init_stacks(argc, argv, stacks);
	receive_game_opes(stacks);
	if (check_sort_stack(stacks[A]) == 1 && stacks[B].depth == 0)
		write(STDERR_FILENO, "OK\n", 3);
	else
		write(STDERR_FILENO, "KO\n", 3);
	free_stacks_array(stacks);
	return (0);
}
