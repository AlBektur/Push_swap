/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 05:42:13 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/22 08:40:45 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
123

132

213

231

312

321
*/
static void	sort_3(t_list **stack, t_flags *flags)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = first->next;
	third = second->next;

	// if (first->data < second->data && second->data > third->data)
	// {
	// 	rra(stack, flags);
	// 	sa(stack, flags);
	// }
	// else if (first->data > second->data && first->data < third->data)
	// 	sa(stack, flags);

	// else if (first->data < second->data && first->data > third->data)
	// 	rra(stack, flags);
	// else if (first->data > second->data && first->data > third->data)
	// {
	// 	ra(stack, flags);
	// 	sa(stack, flags);
	// }
	// else if (first->data > second->data && second->data > third->data)
	// {
	// 	sa(stack, flags);
	// 	rra(stack, flags);
	//}

}
void	mini_sort(t_list **stack_a, t_list	**stack_b, t_flags *flags)
{
	int	size;

	size = ft_lstsize(*stack_a);


	//printf("size of stack: %d\n", size);

	sort_3(stack_a, flags);
}
