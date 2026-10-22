/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:20:10 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/22 05:27:15 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	is_valid_split(char const *tokens)
{
	int	i;

	if (!tokens)
		return (-1);
	i = 0;
	while (tokens[i])
	{
		if (tokens[i] >= '0' && tokens[i] <= '9')
			return (1);
		i++;
	}
	return (-1);
}

static int	split_controler(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '-' || token[i] == '+')
		i++;
	while (token[i])
	{
		if (!(token[i] >= '0' && token[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static void	split_controler_2_2(char **tokens)
{
	ft_split_cleaner(tokens);
	write(2, "Error\n", 6);
	exit(1);
}

static void	split_controler_2(char *token, char **tokens)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (token[i] == ' ' || (token[i] >= 9 && token[i] <= 13))
		i++;
	if (token[i] == '-' || token[i] == '+')
	{
		if (token[i] == '-')
			sign *= -1;
		i++;
	}
	while (token[i] >= '0' && token[i] <= '9')
	{
		res = res * 10 + (token[i] - '0');
		i++;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN)
		split_controler_2_2(tokens);
}

void	ft_split_controler(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (split_controler(tokens[i]) != 1)
		{
			ft_split_cleaner(tokens);
			write(1, "Error\n", 6);
			exit(1);
		}
		split_controler_2(tokens[i], tokens);
		i++;
	}
}
