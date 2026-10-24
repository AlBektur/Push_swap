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
	while (temp)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void	sort_adaptive_mode(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	if (flags->disorder < 2000)
		selection_sort(stack_a, stack_b, flags);
	else if (flags->disorder >= 2000 && flags->disorder < 5000)
		sort_medium(stack_a, stack_b, flags);
	else if (flags->disorder >= 5000)
		sort_complex(stack_a, stack_b, flags);
}

void	sort(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	if (ft_lstsize(*stack_a) < 6)
		mini_sort(stack_a, stack_b, flags);
	else
	{
		if (flags->alg_type == 1)
			sort_adaptive_mode(stack_a, stack_b, flags);
		else if (flags->alg_type == 2)
			selection_sort(stack_a, stack_b, flags);
		else if (flags->alg_type == 3)
			sort_medium(stack_a, stack_b, flags);
		else if (flags->alg_type == 4)
			sort_complex(stack_a, stack_b, flags);
	}
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
	compute_disorder(stack_a, flags);
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b, flags);
	if (flags->bench)
		make_bench(flags);
	ft_killer(stack_a);
	ft_killer(stack_b);
	return (0);
}
