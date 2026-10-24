/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 04:37:04 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/23 05:58:14 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	ft_putnbr(int nb)
{
	char	n;

	if (nb == INT_MIN)
	{
		write(2, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(2, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	n = nb % 10 + '0';
	write(2, &n, 1);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

static void	bench_print_alg_type(int n)
{
	char	*algorithms[5];

	algorithms[0] = "Adaptive / O(n√n)";
	algorithms[1] = "Simple / O(n2)";
	algorithms[2] = "Medium / O(n√n)";
	algorithms[3] = "Complex / O(n log n)";
	algorithms[4] = NULL;
	ft_putstr(algorithms[n]);
}

void	make_bench_aux(t_flags *flags)
{
	write(2, "\n[bench] ", 9);
	write(2, "sa: ", 4);
	ft_putnbr(flags->sa);
	write(2, " sb: ", 5);
	ft_putnbr(flags->sb);
	write(2, " ss: ", 5);
	ft_putnbr(flags->ss);
	write(2, " pa: ", 5);
	ft_putnbr(flags->pa);
	write(2, " pb: ", 5);
	ft_putnbr(flags->pb);
	write(2, "\n[bench] ", 9);
	write(2, "ra: ", 4);
	ft_putnbr(flags->ra);
	write(2, " rb: ", 5);
	ft_putnbr(flags->rb);
	write(2, " rr: ", 5);
	ft_putnbr(flags->rr);
	write(2, " rra: ", 6);
	ft_putnbr(flags->rra);
	write(2, " rrb: ", 6);
	ft_putnbr(flags->rrb);
	write(2, " rrr: ", 6);
	ft_putnbr(flags->rrr);
}

void	make_bench(t_flags *flags)
{
	write(2, "[bench] disorder: ", 18);
	ft_putnbr(flags->disorder / 100);
	write(2, ".", 1);
	if (flags->disorder % 100 < 10)
		write(2, "0", 1);
	ft_putnbr(flags->disorder % 100);
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 18);
	bench_print_alg_type(--flags->alg_type);
	write(2, "\n[bench] total_ops: ", 20);
	ft_putnbr(flags->total_op);
	make_bench_aux(flags);
}
