/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 05:42:13 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/23 02:21:24 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	sort_3(t_list **stack, t_flags *flags)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (second->data > third->data && third->data > first->data)
	{
		rra(stack, flags);
		sa(stack, flags);
	}
	else if (third->data > first->data && first->data > second->data)
		sa(stack, flags);
	else if (second->data > first->data && first->data > third->data)
		rra(stack, flags);
	else if (first->data > third->data && third->data > second->data)
		ra(stack, flags);
	else if (first->data > second->data && second->data > third->data)
	{
		ra(stack, flags);
		sa(stack, flags);
	}
}

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

void	mini_sort(t_list **stack_a, t_list	**stack_b, t_flags *flags)
{
	while (ft_lstsize(*stack_a) > 3)
		send_min_val(stack_a, stack_b, flags);
	sort_3(stack_a, flags);
	while (ft_lstsize(*stack_b) > 0)
		push_a(stack_b, stack_a, flags);
}
