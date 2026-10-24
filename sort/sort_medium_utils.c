#include "../includes/header.h"

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

static int	*alloc_ranks(t_list *stack, int n)
{
	int	*ranks;

	ranks = malloc(sizeof(int) * n);
	if (ranks == NULL)
	{
		ft_killer(stack);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (ranks);
}

void	normalize_ranks(t_list *stack, int n)
{
	int		*ranks;
	t_list	*cur;
	int		k;

	ranks = alloc_ranks(stack, n);
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

int	get_max_index(t_list *b)
{
	t_list	*cur;
	int		idx;
	int		max_idx;
	int		max;

	cur = b;
	idx = 0;
	max_idx = 0;
	max = b->data;
	while (cur != NULL)
	{
		if (cur->data > max)
		{
			max = cur->data;
			max_idx = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (max_idx);
}

void	bring_top_b(t_list **b, int idx, int size, t_flags *flags)
{
	if (idx <= size / 2)
	{
		while (idx-- > 0)
			rb(b, flags);
	}
	else
	{
		idx = size - idx;
		while (idx-- > 0)
			rrb(b, flags);
	}
}
