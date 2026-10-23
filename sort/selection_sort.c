/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 02:43:55 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/23 02:57:24 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	send_min_val(t_list **stack_a, t_list	**stack_b, t_flags *flags)
{
	t_list	*temp;
	int		min;

	temp = *stack_a;
	min = (*stack_a)->data;
	while (temp)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	temp = *stack_a;
	while ((*stack_a)->data != min)
		ra(stack_a, flags);
	push_b(stack_a, stack_b, flags);
}

void	selection_sort(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	while (ft_lstsize(*stack_a) > 0)
		send_min_val(stack_a, stack_b, flags);
	while (ft_lstsize(*stack_b) > 0)
		push_a(stack_b, stack_a, flags);
}
