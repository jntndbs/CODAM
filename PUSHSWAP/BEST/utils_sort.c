#include "push_swap.h"

void	act_arr_reset(t_sort *s)
{
	short	i;

	i = 0;
	while (i < 8)
	{
		s->act_arr[i] = 0;
		i++;
	}
	return ;
}

// Returns 'ok' if stack is sorted ascending, 'err' if not
short	check_sort_asc(t_list **head)
{
	t_list	*tmp;
	int		prev_index;
	
	if (!*head)
		return (err);
	tmp = *head;
	while (tmp->next != NULL)
	{
		prev_index = tmp->num;
		tmp = tmp->next;
		if (tmp->num < prev_index)
			return (err);
	}
	return (ok);
}
