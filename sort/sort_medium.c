#include "../includes/header.h"

static int	ps_isqrt(int n)
{
	int	r;

	r = 1;
	while (r * r <= n)
		r++;
	return (r - 1);
}

static void	push_to_b(t_list **a, t_list **b, t_flags *flags)
{
	int	chunk;
	int	upper;

	chunk = ps_isqrt(ft_lstsize(*a)) + 1;
	upper = chunk;
	while (*a != NULL)
	{
		if ((*a)->data < upper)
		{
			push_b(a, b, flags);
			if (ft_lstsize(*b) >= upper)
				upper += chunk;
		}
		else
			ra(a, flags);
	}
}

static void	pull_to_a(t_list **a, t_list **b, t_flags *flags)
{
	int	idx;
	int	size;

	while (*b != NULL)
	{
		size = ft_lstsize(*b);
		idx = get_max_index(*b);
		bring_top_b(b, idx, size, flags);
		push_a(b, a, flags);
	}
}

void	sort_medium(t_list **a, t_list **b, t_flags *flags)
{
	if (ft_lstsize(*a) < 2)
		return ;
	normalize_ranks(*a, ft_lstsize(*a));
	push_to_b(a, b, flags);
	pull_to_a(a, b, flags);
}
