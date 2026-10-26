/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 02:11:00 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/26 04:56:03 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../includes/bonus_header.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n && (s1[j] || s2[j]))
	{
		if ((unsigned char)s1[j] != (unsigned char)s2[j])
			return (0);
		j++;
	}
	return (1);
}

void	make_op(t_list **stack_a, t_list **stack_b, t_flags *flags, char *line)
{
	if (ft_strncmp(line, "sa\n", 3))
		sa(stack_a, flags);
	else if (ft_strncmp(line, "sb\n", 3))
		sb(stack_b, flags);
	else if (ft_strncmp(line, "ss\n", 3))
		ss(stack_a, stack_b, flags);
	else if (ft_strncmp(line, "pa\n", 3))
		push_a(stack_b, stack_a, flags);
	else if (ft_strncmp(line, "pb\n", 3))
		push_b(stack_a, stack_b, flags);
	else if (ft_strncmp(line, "ra\n", 3))
		ra(stack_a, flags);
	else if (ft_strncmp(line, "rb\n", 3))
		rb(stack_b, flags);
	else if (ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b, flags);
	else if (ft_strncmp(line, "rra\n", 4))
		rra(stack_a, flags);
	else if (ft_strncmp(line, "rrb\n", 4))
		rrb(stack_b, flags);
	else if (ft_strncmp(line, "rrr\n", 4))
		rrr(stack_a, stack_b, flags);
	else
		return ;
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_flags	*flags;
	t_flags	node_for_flags;
	char	*line;

	flags = &node_for_flags;
	stack_b = NULL;
	init_flags(flags);
	flags->checker = 1;
	def_flags(&argc, &argv, flags);
	stack_a = make_stack(argc, argv);
	line = get_next_line(0);
	while (line != NULL)
	{
		make_op(&stack_a, &stack_b, flags, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
