/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:31:13 by mkamei            #+#    #+#             */
/*   Updated: 2021/07/23 18:11:12 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_top(t_list **any_stack, t_list *new_list)
{
	ft_lstadd_front(any_stack, new_list);
}

void	push_to_stack_bottom(t_list **any_stack, t_list *new_list)
{
	ft_lstadd_back(any_stack, new_list);
}

t_list	*pop_from_stack_top(t_list **any_stack)
{
	t_list	*top_list;

	if (*any_stack == NULL)
		return (NULL);
	top_list = *any_stack;
	*any_stack = top_list->next;
	top_list->next = NULL;
	return (top_list);
}

t_list	*pop_from_stack_bottom(t_list **any_stack)
{
	t_list	*prev_list;
	t_list	*current_list;

	if (*any_stack == NULL)
		return (NULL);
	prev_list = NULL;
	current_list = *any_stack;
	while (current_list->next != NULL)
	{
		prev_list = current_list;
		current_list = current_list->next;
	}
	if (prev_list != NULL)
		prev_list->next = NULL;
	return (current_list);
}
