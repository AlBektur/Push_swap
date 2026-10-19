/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:27:50 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/19 05:27:50 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*first;
	t_list	*last;

	last = *stack_a;
	first = *stack_a;
	head = first->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*stack_a = head;
	write(1, "ra\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	second = *stack_a;
	last = *stack_a;
	while (last->next->next != NULL)
		last = last->next;
	first = last->next;
	first->next = second;
	last->next = NULL;
	*stack_a = first;
	write(1, "rra\n", 4);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_1_first;

	stack_1_first = *stack_a;
	*stack_a = stack_1_first->next;
	stack_1_first->next = *stack_b;
	*stack_b = stack_1_first;
	write(1, "pb\n", 3);
}
