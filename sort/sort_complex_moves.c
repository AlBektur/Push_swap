/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 05:01:39 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/26 05:01:43 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	take_val(t_ctx *c, int loc)
{
	if (loc == TA)
		return ((*c->a)->data);
	if (loc == BA)
		return (last_node(*c->a)->data);
	if (loc == TB)
		return ((*c->b)->data);
	return (last_node(*c->b)->data);
}

void	move_one_to_ta(t_ctx *c, int loc)
{
	if (loc == BA)
		rra(c->a, c->f);
	else if (loc == TB)
		push_a(c->b, c->a, c->f);
	else if (loc == BB)
	{
		rrb(c->b, c->f);
		push_a(c->b, c->a, c->f);
	}
}

static void	move_from_a(t_ctx *c, int loc, int cls)
{
	if (loc == BA)
		rra(c->a, c->f);
	if (cls == 0)
	{
		if (loc == TA)
			ra(c->a, c->f);
		return ;
	}
	push_b(c->a, c->b, c->f);
	if (cls == 2)
		rb(c->b, c->f);
}

static void	move_from_b(t_ctx *c, int loc, int cls)
{
	if (loc == BB)
		rrb(c->b, c->f);
	if (cls == 2)
	{
		if (loc == TB)
			rb(c->b, c->f);
		return ;
	}
	push_a(c->b, c->a, c->f);
	if (cls == 1)
		ra(c->a, c->f);
}

void	split_move(t_ctx *c, int loc, int cls)
{
	if (loc == TA || loc == BA)
		move_from_a(c, loc, cls);
	else
		move_from_b(c, loc, cls);
}
