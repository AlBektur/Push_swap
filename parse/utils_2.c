/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:20:03 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/19 05:20:06 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	is_valid_split(char const *tokens)
{
	int	i;

	if (!tokens)
		return (-1);
	i = 0;
	while (tokens[i])
	{
		if (tokens[i] >= '0' && tokens[i] <= '9')
			return (1);
		i++;
	}
	return (-1);
}

void	is_sorted(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return ;
	}
	ft_killer(stack_a);
	exit(2);
}

int	list_size(t_list **stack)
{
	t_list	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	is_sorted_list(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (-1);
	}
	return (1);
}
