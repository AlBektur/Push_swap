/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:20:28 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/19 05:20:41 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	is_valid(char *token, t_list *head)
{
	int	i;

	i = 0;
	if (token[i] == '\0')
	{
		write(2, "Error\n", 6);
		ft_killer(head);
		exit(1);
	}
	while (token[i])
	{
		if ((!(token[i] >= '0' && token[i] <= '9')))
		{
			write(2, "Error\n", 6);
			ft_killer(head);
			exit(1);
		}
		i++;
	}
}

static void	min_max_checker(long res, t_list *head)
{
	if (res < INT_MIN || res > INT_MAX)
	{
		write(2, "Error\n", 6);
		ft_killer(head);
		exit(1);
	}
}

long	ft_atol(char *token, t_list *head)
{
	long	res;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	res = 0;
	while ((token[i] >= 9 && token[i] <= 13) || (token[i] == ' '))
		i++;
	if (token[i] == '-' || token[i] == '+')
	{
		if (token[i] == '-')
			sign *= -1;
		i++;
	}
	is_valid(&token[i], head);
	while (token[i] >= '0' && token[i] <= '9')
		res = res * 10 + (token[i++] - '0');
	res *= sign;
	min_max_checker(res, head);
	return (res);
}
