#include "push_swap.h"

// 3 stage algorithm
// 1st stage: pushing lowest value possible with only 2 actions to b
// 2nd stage: hard-sorting the 3 remaining values in a
// 3rd stage: finding the most efficient value to push back to a
short	algo_swap_push(t_list **head_a, t_list **head_b, t_sort *s, \
		const short *arr)
{
	if (list_len(head_a) > 3 && check_sort_asc(head_a) != ok)
	{
		if (fsl_sort(head_a, head_b, s, arr) != ok)
			return (err);
	}
	if (check_sort_asc(head_a) != ok)
	{
		if (hardsort(head_a, head_b, st_a))
			return (err);
	}
	if (check_sort_asc(head_a) != ok && list_len(head_b) == 0)
	{
		return (ok);
		// LEFTOFF third stage!
	}
	return (ok);
}