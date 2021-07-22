/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:50:49 by mkamei            #+#    #+#             */
/*   Updated: 2021/07/22 16:03:38 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack[2])
{
	int		i;
	t_list	*current_list;
	char	*nbr_str;

	i = 0;
	while (i <= 1)
	{
		current_list = stack[i];
		if (i == 0)
			write(1, "A: ", 3);
		else
			write(1, "B: ", 3);
		while (current_list != NULL)
		{
			nbr_str = ft_itoa(*((int *)current_list->content));
			if (nbr_str == NULL)
				return ;
			write(1, nbr_str, ft_strlen(nbr_str));
			write(1, " ", 1);
			free(nbr_str);
			current_list = current_list->next;
		}
		write(1, "\n", 1);
		i++;
	}
}
