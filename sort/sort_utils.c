/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 06:36:56 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/22 15:53:04 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_lstsize(t_list *lst)
{
	int	i;
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_list	*last_node(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	is_sorted(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
