/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:28:01 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/19 05:28:03 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*head;
	t_list	*first;
	t_list	*last;

	last = *stack_b;
	first = *stack_b;
	head = first->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*stack_b = head;
	write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	second = *stack_b;
	last = *stack_b;
	while (last->next->next != NULL)
		last = last->next;
	first = last->next;
	first->next = second;
	last->next = NULL;
	*stack_b = first;
	write(1, "rrb\n", 4);
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*stack_1_first;

	stack_1_first = *stack_b;
	*stack_b = stack_1_first->next;
	stack_1_first->next = *stack_a;
	*stack_a = stack_1_first;
	write(1, "pa\n", 3);
}
