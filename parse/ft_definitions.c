/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_definitions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 01:45:54 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/22 16:58:23 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	init_flags(t_flags *flags)
{
	flags->bench = 0;
	flags->alg_type = 1;
	flags->disorder = 0;
	flags->sa = 0;
	flags->sb = 0;
	flags->ss = 0;
	flags->pa = 0;
	flags->pb = 0;
	flags->ra = 0;
	flags->rb = 0;
	flags->rr = 0;
	flags->rra = 0;
	flags->rrb = 0;
	flags->rrr = 0;
	flags->total_op = 0;
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

static int	ft_def_flags_aux(char **algorithms, char *flag)
{
	int	i;

	i = 0;
	while (algorithms[i])
	{
		if (ft_strcmp(algorithms[i], flag))
			return (++i);
		i++;
	}
	return (0);
}

static void	def_algorithms(t_flags *flags, int *argc, char **params[])
{
	char	*algorithms[5];

	algorithms[0] = "--adaptive";
	algorithms[1] = "--simple";
	algorithms[2] = "--medium";
	algorithms[3] = "--complex";
	algorithms[4] = NULL;
	if (*argc > 1)
	{
		flags->bench = ft_strcmp((*params)[1], "--bench");
		flags->alg_type = ft_def_flags_aux(algorithms, (*params)[1]);
		if (*argc > 2)
		{
			if (flags->bench == 0)
				flags->bench = ft_strcmp((*params)[2], "--bench");
			if (flags->alg_type == 0)
				flags->alg_type = ft_def_flags_aux(algorithms, (*params)[2]);
		}
	}
}

void	def_flags(int *argc, char **params[], t_flags *flags)
{
	int		i;
	int		counter;

	counter = 0;
	def_algorithms(flags, argc, params);
	if (flags->bench != 0)
		counter++;
	if (flags->alg_type != 0)
		counter++;
	if (flags->alg_type == 0)
		flags->alg_type = 1;
	(*params) += counter;
	(*argc) -= counter;
}
