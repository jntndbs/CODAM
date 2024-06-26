#include "push_swap.h"

int	bn(int one, int two)
{
	if (one > two)
		return (one);
	return (two);
}

int	sn(int one, int two)
{
	if (one < two)
		return (one);
	return (two);
}

short	smallest(t_list **a, int val)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->n_i < val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	smallest_node_rotate_a(t_list **a)
{
	int		i;
	int		i_small;
	int		small;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	small = INT_MAX;
	while (tmp != NULL)
	{
		if (tmp->n_i < small)
		{
			small = tmp->n_i;
			i_small = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (i_small);
}

int	biggest_node_rotate_a(t_list **a)
{
	int		i;
	int		i_big;
	int		big;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	big = INT_MIN;
	while (tmp != NULL)
	{
		if (tmp->n_i > big)
		{
			big = tmp->n_i;
			i_big = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (i_big + 1);
}

int	abs(int val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

int	rotate_amount_a(t_list **a, int val)
{
	t_list	*tmp;
	int		bindex;
	int		i;
	int		diff;
	int		small;

	if (!(a) || !(*a))
		return (0);
	// if (smallest(a, val))
	// 	return (smallest_node_rotate_a(a));
	tmp = *a;
	small = INT_MAX;
	i = 0;
	bindex = -1;
	while (tmp != NULL)
	{
		diff = abs(val - tmp->num);
		if (diff < small && val < tmp->num)
		{
			small = diff;
			bindex = i;
		}
		++i;
		tmp = tmp->next;
	}
	if (bindex == -1)
		return (biggest_node_rotate_a(a));
	return (bindex);
}

// int	rotate_amount_a(t_list **a, int val)//TEST!!!
// {
// 	t_list			*tmp;
// 	const t_list	*last_a = last_node(a);
// 	int				i;

// 	if (last_a == NULL)
// 		return (0);
// 	if (smallest(a, val))
// 		return (smallest_node_rotate_a(a));
// 	i = 0;
// 	tmp = *a;
// 	while (tmp != NULL)
// 	{
// 		if (i == 0 && tmp->num > val && last_a->num < val)
// 			return (0);
// 		if (tmp == last_a && tmp->num < val && (*a)->num > val)
// 			return (i);
// 		if (tmp != last_a && tmp->num < val && tmp->next->num > val)
// 			return (i + 1);
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	printf(">> biggest: %i\n", val);// TEST
// 	return (biggest_node_rotate_a(a));
// }

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
