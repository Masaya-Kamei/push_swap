/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:24:41 by mkamei            #+#    #+#             */
/*   Updated: 2021/07/22 16:35:48 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_status	atoi_with_check(char *str, int *nbr)
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
			|| (str[0] == '-' && -long_nbr < INT32_MIN))
			return (ERROR);
		i++;
	}
	if (str[0] == '-')
		long_nbr *= -1;
	*nbr = long_nbr;
	return (SUCCESS);
}

t_status	check_nbr_duplicate_in_stack(t_list *any_stack, int nbr)
{
	t_list	*current_list;

	current_list = any_stack;
	while (current_list != NULL)
	{
		if (*(int *)current_list->content == nbr)
			return (ERROR);
		current_list = current_list->next;
	}
	return (SUCCESS);
}

int		push_new_nbr_to_stack(t_list **any_stack, int nbr)
{
	t_list	*new_list;
	int		*new_nbr;

	new_nbr = (int *)malloc(sizeof(int) * 1);
	if (new_nbr == NULL)
		return (ERROR);
	*new_nbr = nbr;
	new_list = ft_lstnew(new_nbr);
	if (new_list == NULL)
		return (ERROR);
	ft_lstadd_front(any_stack, new_list);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	int			i;
	int			nbr;
	t_list		*stack[2];

	if (argc <= 1)
		return (0);
	i = 1;
	stack[A] = NULL;
	stack[B] = NULL;
	while (argv[i] != NULL)
	{
		if (atoi_with_check(argv[i], &nbr) == ERROR
			|| check_nbr_duplicate_in_stack(stack[A], nbr) == ERROR
			|| push_new_nbr_to_stack(&stack[A], nbr) == ERROR)
		{
			ft_lstclear(&stack[A], free);
			ft_lstclear(&stack[B], free);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	print_stack(stack);
	return (0);
}

