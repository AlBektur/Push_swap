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
	int	pushed;

	chunk = ps_isqrt(ft_lstsize(*a)) * 14 / 10;
	pushed = 0;
	while (*a != NULL)
	{
		if ((*a)->data <= pushed)
		{
			push_b(a, b, flags);
			rb(b, flags);
			pushed++;
		}
		else if ((*a)->data <= pushed + chunk)
		{
			push_b(a, b, flags);
			pushed++;
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
