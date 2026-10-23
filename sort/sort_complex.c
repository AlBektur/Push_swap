#include "header.h"

static int	count_smaller(t_list *stack, int value)
{
	t_list	*cur;
	int		count;

	cur = stack;
	count = 0;
	while (cur != NULL)
	{
		if (cur->data < value)
			count++;
		cur = cur->next;
	}
	return (count);
}

static void	index_stack(t_list *stack, int n)
{
	int		*ranks;
	t_list	*cur;
	int		k;

	ranks = malloc(sizeof(int) * n);
	if (ranks == NULL)
	{
		ft_killer(stack);
		write(2, "Error\n", 6);
		exit(1);
	}
	cur = stack;
	k = 0;
	while (cur != NULL)
	{
		ranks[k++] = count_smaller(stack, cur->data);
		cur = cur->next;
	}
	cur = stack;
	k = 0;
	while (cur != NULL)
	{
		cur->data = ranks[k++];
		cur = cur->next;
	}
	free(ranks);
}

static void	radix_pass(t_list **a, t_list **b, t_flags *flags, int bit)
{
	int	i;
	int	size;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		if ((((*a)->data >> bit) & 1) == 0)
			push_b(a, b, flags);
		else if ((*a)->next != NULL)
			ra(a, flags);
		i++;
	}
	while (*b != NULL)
		push_a(b, a, flags);
}

void	sort_complex(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	int	size;
	int	max_bit;
	int	bit;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	index_stack(*stack_a, size);
	max_bit = 0;
	while ((size - 1) >> max_bit)
		max_bit++;
	bit = 0;
	while (bit < max_bit)
	{
		radix_pass(stack_a, stack_b, flags, bit);
		bit++;
	}
}
