/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 05:01:39 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/26 05:01:43 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int	chunk_dest(int loc, int cls)
{
	if (cls == 0 && loc == TA)
		return (BA);
	if (cls == 0)
		return (TA);
	if (cls == 1 && (loc == TA || loc == BA))
		return (TB);
	if (cls == 1)
		return (BA);
	if (loc == BB)
		return (TB);
	return (BB);
}

static void	sort_chunk(t_ctx *c, int loc, int lo, int n)
{
	int	third;
	int	two;
	int	i;
	int	v;

	if (n <= 0)
		return ;
	loc = to_top(c, loc, n);
	n = easy_sort(c, &loc, lo, n);
	if (n <= 3)
	{
		small_sort(c, loc, n);
		return ;
	}
	third = lo + n / 3;
	two = lo + 2 * n / 3;
	i = 0;
	while (i++ < n)
	{
		v = take_val(c, loc);
		split_move(c, loc, (v < two) + (v < third));
	}
	sort_chunk(c, chunk_dest(loc, 0), two, lo + n - two);
	sort_chunk(c, chunk_dest(loc, 1), third, two - third);
	sort_chunk(c, chunk_dest(loc, 2), lo, third - lo);
}

void	sort_complex(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	t_ctx	c;
	int		n;

	n = ft_lstsize(*stack_a);
	if (n < 2 || is_sorted(*stack_a))
		return ;
	normalize_ranks(*stack_a, n);
	c.a = stack_a;
	c.b = stack_b;
	c.f = flags;
	sort_chunk(&c, TA, 0, n);
}
