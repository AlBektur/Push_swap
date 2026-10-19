/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:19:16 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/19 05:19:16 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_print_stack(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while(temp)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
}
int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = make_stack(argc, argv);
	is_sorted(stack_a);
	stack_b = NULL;

	ft_print_stack(stack_a);
	return (0);
}
