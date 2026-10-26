#include "../includes/header.h"

void	ss(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	swap_list(stack_a);
	swap_list(stack_b);
	if (!flags->checker)
		write(1, "ss\n", 3);
	flags->ss += 1;
	flags->total_op += 1;
}

void	rr(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	rotate_list(stack_a);
	rotate_list(stack_b);
	if (!flags->checker)
		write(1, "rr\n", 3);
	flags->rr += 1;
	flags->total_op += 1;
}

void	rrr(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	rev_rotate_list(stack_a);
	rev_rotate_list(stack_b);
	if (!flags->checker)
		write(1, "rrr\n", 4);
	flags->rrr += 1;
	flags->total_op += 1;
}
