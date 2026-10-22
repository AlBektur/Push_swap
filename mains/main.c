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
	printf("\n");
}


int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_flags	*flags;
	t_flags	node_for_flags;

	flags = &node_for_flags;
	stack_b = NULL;

	init_flags(flags);
	def_flags(&argc, &argv, flags);

	stack_a = make_stack(argc, argv);

	//this function sorts if stack size <= 5
	//mini_sort(&stack_a, &stack_b, flags);


	compute_disorder(stack_a, flags);
	ft_killer(stack_a);
	ft_killer(stack_b);

	return (0);
}
