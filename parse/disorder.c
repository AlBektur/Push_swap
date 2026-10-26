/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 05:00:39 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/26 05:00:43 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	compute_disorder(t_list *stack_a, t_flags *flags)
{
	t_list	*i;
	t_list	*j;
	long	mistakes;
	long	n;

	mistakes = 0;
	n = ft_lstsize(stack_a);
	i = stack_a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (n < 2)
		flags->disorder = 0;
	else
		flags->disorder = (int)(mistakes * 10000 / (n * (n - 1) / 2));
}
