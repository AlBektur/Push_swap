/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:19:30 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/23 05:09:45 by besaipid         ###   ########.fr       */
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


typedef	struct s_flags
{

	/*
	it is --adaptive por default;

	1 = "--adaptive";
	2 = "--simple";
	3 = "--medium";
	4 = "--complex";
	*/
	int	alg_type;
	int	bench; // if there is a falg --bench it will equal to 1, else to -1
	int	disorder;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_op;
} t_flags;

// aux function needs to be deleted
void	ft_print_stack(t_list *stack);
void	make_bench(t_flags *flags);

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

void	init_flags(t_flags *flags);
void	def_flags(int *argc, char **params[], t_flags *flags);
void	compute_disorder(t_list *stack_a, t_flags *flags);

//Op functions
void	sa(t_list **stack_a, t_flags *flags);
void	ra(t_list **stack_a, t_flags *flags);
void	rra(t_list **stack_a, t_flags *flags);
void	push_b(t_list **stack_a, t_list **stack_b, t_flags *flags);

void	sb(t_list **stack_b, t_flags *flags);
void	rb(t_list **stack_b, t_flags *flags);
void	rrb(t_list **stack_b, t_flags *flags);
void	push_a(t_list **stack_b, t_list **stack_a, t_flags *flags);



/// we start sorting here
void	send_min_val(t_list **stack_a, t_list	**stack_b, t_flags *flags);
int	ft_lstsize(t_list *lst);
//list with maximum 5 nodes
void	mini_sort(t_list **stack_a, t_list	**stack_b, t_flags *flags);

// for --simple mode
void	selection_sort(t_list **stack_a, t_list **stack_b, t_flags *flags);

// for --medium mode
void	sort_medium(t_list **stack_a, t_list **stack_b, t_flags *flags);
void	normalize_ranks(t_list *stack, int n);
int		get_max_index(t_list *b);
void	bring_top_b(t_list **b, int idx, int size, t_flags *flags);

// for --complex mode
void	sort_complex(t_list **stack_a, t_list **stack_b, t_flags *flags);
#endif
