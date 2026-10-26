/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 02:43:55 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/26 05:37:48 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	find_min_val(t_list *temp, int	*idx, int *i)
{
	int	min;
	int	j;

	j = 0;
	min = temp->data;
	while (temp)
	{
		if (min > temp->data)
		{
			min = temp->data;
			*idx = j;
		}
		temp = temp->next;
		j++;
	}
	*i = j;
	return (min);
}

void	send_min_val(t_list **stack_a, t_list	**stack_b, t_flags *flags)
{
	t_list	*temp;
	int		min;
	int		idx;
	int		i;
	int		j;

	j = 0;
	temp = *stack_a;
	idx = 0;
	i = 0;
	min = find_min_val(temp, &idx, &i);
	while ((*stack_a)->data != min)
	{
		if (idx <= i / 2)
			ra(stack_a, flags);
		else
			rra(stack_a, flags);
	}
	push_b(stack_a, stack_b, flags);
}

void	selection_sort(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	while (ft_lstsize(*stack_a) > 0)
		send_min_val(stack_a, stack_b, flags);
	while (ft_lstsize(*stack_b) > 0)
		push_a(stack_b, stack_a, flags);
}
