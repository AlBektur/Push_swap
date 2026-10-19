/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:19:30 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/19 05:19:33 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	int					data;
	struct s_list		*next;
}	t_list;

// Parsing functions
t_list	*make_stack(int size, char **tokens);
long	ft_atol(char *token, t_list *head);
void	ft_killer(t_list *stack);
void	ft_split_cleaner(char **res);
void	array_killer(int *array, t_list **stack_a);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		is_valid_split(char const *tokens);
void	ft_split_controler(char **tokens);

// the function to check if the given arguments are sorted already
void	is_sorted(t_list *stack_a);

//Op functions
void	sa(t_list **stack_a);
void	ra(t_list **stack_a);
void	rra(t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);

void	sb(t_list **stack_b);
void	rb(t_list **stack_b);
void	rrb(t_list **stack_b);
void	push_a(t_list **stack_b, t_list **stack_a);

#endif
