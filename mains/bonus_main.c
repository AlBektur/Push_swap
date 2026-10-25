/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 02:11:00 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/25 05:26:49 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../includes/bonus_header.h"

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

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

// "sa\n"
// "sb\n"
// "ss\n"
// "pa\n"
// "pb\n"
// "ra\n"
// "rb\n"
// "rr\n"
// "rra\n";
// "rrb\n";
// "rrr\n";

void	make_op(t_list **stack_a, t_list **stack_b, t_flags *flags, char *command)
{
	if (ft_strcmp(command, "sa\n"))
		ra(stack_a, flags);
	// else if (ft_strcmp(command, "sb\n"))
	// 	sb(stack_b, flags);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	buffer[5];
	t_flags	*flags;
	t_flags	node_for_flags;

	flags = &node_for_flags;
	stack_b = NULL;
	init_flags(flags);
	def_flags(&argc, &argv, flags);

	stack_a = make_stack(argc, argv);
	ft_print_stack(stack_a);

	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		make_op(&stack_a, &stack_b, flags, line);
		free(line);
		line = get_next_line(0);

	}

	if (is_sorted(stack_a) && stack_b == NULL)
		printf("OK\n");
	else
		printf("KO\n");

	return (0);
}
