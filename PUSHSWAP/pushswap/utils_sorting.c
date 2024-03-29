#include "push_swap.h"

double	sortedness_asc(t_list **head)
{
	long			total_dif;
	int				hold;
	double			sorted;
	const double	len = list_len(head);
	t_list			*tmp;

	if (!head || !*head || (int)len < 2)
		return (0);
	tmp = *head;
	total_dif = 0;
	stack_indexer(head);
	while (tmp->next != NULL)
	{
		hold = tmp->stack_iv;
		tmp = tmp->next;
		hold = tmp->stack_iv - hold;
		if (hold < 0)
			hold *= -2;
		total_dif += hold;
	}
	sorted = (len - 1.0) / (double)total_dif;
	sorted = ((len / ((double)total_dif + 1.0)) + sorted) / 2.0;
	return (sorted);
}

double	sortedness_des(t_list **head)
{
	long			total_dif;
	int				hold;
	double			sorted;
	const double	len = list_len(head);
	t_list			*tmp;

	if (!head || !*head || (int)len < 2)
		return (0);
	tmp = *head;
	total_dif = 0;
	stack_indexer(head);
	while (tmp->next != NULL)
	{
		hold = tmp->stack_iv;
		tmp = tmp->next;
		hold = hold - tmp->stack_iv;
		if (hold < 0)
			hold *= -2;
		total_dif += hold;
	}
	sorted = (len - 1.0) / (double)total_dif;
	sorted = ((len / ((double)total_dif + 1.0)) + sorted) / 2.0;
	return (sorted);
}
