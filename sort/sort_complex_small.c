/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 05:01:39 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/26 05:01:43 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	to_top(t_ctx *c, int loc, int n)
{
	if (loc == BB && ft_lstsize(*c->b) == n)
		return (TB);
	if (loc == BA && ft_lstsize(*c->a) == n)
		return (TA);
	return (loc);
}

int	easy_sort(t_ctx *c, int *loc, int lo, int n)
{
	while (n > 0 && *loc != TA && take_val(c, *loc) == lo + n - 1)
	{
		move_one_to_ta(c, *loc);
		n--;
		if (n > 0)
			*loc = to_top(c, *loc, n);
	}
	return (n);
}

static void	sort_top_a(t_ctx *c, int n)
{
	t_list	*a;

	a = *c->a;
	if (n == 3 && ft_lstsize(a) == 3)
	{
		if (a->data > a->next->data && a->data > a->next->next->data)
			ra(c->a, c->f);
		else if (a->next->data > a->next->next->data)
			rra(c->a, c->f);
	}
	else if (n == 3)
	{
		if (a->data > a->next->data)
			sa(c->a, c->f);
		if ((*c->a)->next->data > (*c->a)->next->next->data)
		{
			push_b(c->a, c->b, c->f);
			sa(c->a, c->f);
			push_a(c->b, c->a, c->f);
		}
	}
	if ((*c->a)->data > (*c->a)->next->data)
		sa(c->a, c->f);
}

static void	bring_to_ta(t_ctx *c, int loc, int n)
{
	int	i;

	i = 0;
	while (i++ < n && loc == BA)
		rra(c->a, c->f);
	i = 0;
	while (i++ < n && loc == BB)
		rrb(c->b, c->f);
	i = 0;
	while (i++ < n && (loc == TB || loc == BB))
		push_a(c->b, c->a, c->f);
}

void	small_sort(t_ctx *c, int loc, int n)
{
	if (n <= 0)
		return ;
	if (n == 1)
	{
		move_one_to_ta(c, loc);
		return ;
	}
	bring_to_ta(c, loc, n);
	sort_top_a(c, n);
}
