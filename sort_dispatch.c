#include "./includes/header.h"

void	sort_dispatch(t_list **stack_a, t_list **stack_b, t_flags *flags)
{
	int	type;

	type = flags->alg_type;
	if (type == 1)
	{
		if (flags->disorder < 2000)
			type = 2;
		else if (flags->disorder < 5000)
			type = 3;
		else
			type = 4;
	}
	if (type == 2)
		selection_sort(stack_a, stack_b, flags);
	else if (type == 3)
		sort_medium(stack_a, stack_b, flags);
	else
		sort_complex(stack_a, stack_b, flags);
}
