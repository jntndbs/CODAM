#include "push_swap.h"

static int	bn(int one, int two)
{
	if (one > two)
		return (one);
	return (two);
}

static int	sn(int one, int two)
{
	if (one < two)
		return (one);
	return (two);
}

int	rotate_stack(t_list **stack, int num)
{
	t_list	*tmp;
	int		i;

	if (*stack == NULL)
		return (0);
	i = 0;
	tmp = *stack;
	while (tmp->num > num && tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	weigh(t_list **a, t_list **b, t_sort *s, t_list *node)
{
	const int	r_a = s->index;
	const int	rr_a = list_len(a) - r_a;
	const int	r_b = rotate_stack(b, node->num);
	const int	rr_b = list_len(b) - r_b;

	if (r_a - rr_a > 0 && r_b - rr_b > 0)
		return (bn(rr_a, rr_b) + 1);
	if (r_a - rr_a < 0 && r_b - rr_b < 0)
		return (bn(r_a, r_b) + 1);
	else
		return (sn(r_a, rr_a) + sn(r_b, rr_b) + 1);
}

void	execute_act(t_list **a, t_list **b, t_sort *s, t_list *node)
{
	const int	r_a = s->index;
	const int	rr_a = list_len(a) - r_a;
	const int	r_b = rotate_stack(b, node->num);
	const int	rr_b = list_len(b) - r_b;

	act_arr_reset(s);
	if (r_a - rr_a > 0 && r_b - rr_b > 0)
	{
		if (rr_a > rr_b)
			s->act_arr[_rra] = rr_a - rr_b;
		else
			s->act_arr[_rrb] = rr_b - rr_a;
		s->act_arr[_rrr] = sn(rr_a, rr_b);
	}
	else if (r_a - rr_a < 0 && r_b - rr_b < 0)
	{
		if (r_a > r_b)
			s->act_arr[_ra] = r_a - r_b;
		else
			s->act_arr[_rb] = r_b - r_a;
		s->act_arr[_rr] = sn(r_a, r_b);
	}
	else
	{
		if (r_a > rr_a)
			s->act_arr[_rra] = rr_a;
		else
			s->act_arr[_ra] = r_a;
		if (r_b > rr_b)
			s->act_arr[_rrb] = rr_b;
		else
			s->act_arr[_rb] = r_b;
	}
	s->act_arr[_pb] = 1;
	do_act_arr(a, b, s);
}
