/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:19:55 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/22 04:02:19 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_list	*make_node(int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

static int	arg_counter(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	return (i);
}

static int	is_dup(long value, t_list *head)
{
	t_list	*temp;

	if (head == NULL)
		return (1);
	temp = head;
	while (temp)
	{
		if (temp->data == value)
		{
			ft_killer(head);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

static t_list	*make_list(int argc, char **tokens, int value)
{
	t_list	*temp;
	t_list	*head;
	t_list	*tail;
	int		i;

	head = NULL;
	i = 0;
	while (i < argc)
	{
		value = ft_atol(tokens[i], head);
		if (!is_dup(value, head))
			return (NULL);
		temp = make_node(value);
		if (head == NULL)
			head = temp;
		else
			tail->next = temp;
		tail = temp;
		i++;
	}
	return (head);
}

t_list	*make_stack(int argc, char **argv)
{
	t_list	*head;
	char	**tokens;
	int		size;

	if (argc < 2)
		exit(0);
	else if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		ft_split_controler(tokens);
		size = arg_counter(tokens);
		head = make_list(size, tokens, 0);
		ft_split_cleaner(tokens);
	}
	else
		head = make_list(argc - 1, argv + 1, 0);
	if (head == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (head);
}
