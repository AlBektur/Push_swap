/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:19:16 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/19 05:19:16 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_print_stack(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while(temp)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
}

// This function to define the alghorithm type and should we printout the benchmark


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

int	ft_def_flags_aux(char **algorithms, char *flag)
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




void	def_flags(int *argc, char **argv[], t_flags *flags)
{
	int		i;
	int		counter;

	counter = 0;
	char	*algorithms[5];
	algorithms[0] = "--adaptive";
	algorithms[1] = "--simple";
	algorithms[2] = "--medium";
	algorithms[3] = "--complex";
	algorithms[4] = NULL;

	flags->alg_type = 0;
	flags->bench = 0;
	if (*argc > 1)
	{

		flags->bench = ft_strcmp((*argv)[1], "--bench");
		flags->alg_type = ft_def_flags_aux(algorithms, (*argv)[1]);
		if (*argc > 2)
		{
			if (flags->bench == 0)
				flags->bench = ft_strcmp((*argv)[2], "--bench");
			if (flags->alg_type == 0)
				flags->alg_type = ft_def_flags_aux(algorithms, (*argv)[2]);
		}
	}
	if (flags->bench != 0)
		counter++;
	if (flags->alg_type != 0)
		counter++;
	if (flags->alg_type == 0)
		flags->alg_type = 1;

	(*argv) += counter;
	(*argc) -= counter;


}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_flags	*flags;
	t_flags	node;

	flags	= &node;
	stack_b = NULL;

	def_flags(&argc, &argv, flags);
	stack_a = make_stack(argc, argv);

	ft_print_stack(stack_a);



	ft_killer(stack_a);
	return (0);
}
