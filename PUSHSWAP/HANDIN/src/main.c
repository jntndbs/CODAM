/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:27:14 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/11 16:05:13 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// pb_stage -> pushes values to stack b till 3 remain in stack a
// hardsort -> sorts the three values in stack a
// pa_stage -> pushes the most efficient values back to their right place in a
static void	sorting(t_list **head_a, t_list **head_b, t_sort *s)
{
	if (check_sort_asc(head_a) != ok && s->total_inp > 3)
	{
		pb_stage(head_a, head_b);
		hardsort(head_a, head_b);
		pa_stage(head_a, head_b, s);
	}
	else if (check_sort_asc(head_a) != ok)
		hardsort(head_a, head_b);
}

static short	ft_pushswap(t_list **head_a, t_sort *s)
{
	t_list	*first;
	t_list	**head_b;

	first = NULL;
	head_b = &first;
	if (!*head_a)
		return (err);
	sorting(head_a, head_b, s);
	free_list(head_a);
	free_list(head_b);
	return (ok);
}

static short	single_arg_check(char *str)
{
	int	i;

	if (!str)
		return (err);
	i = 0;
	while (str[i])
	{
		if (i > 0 && (ps_isdigit(str[i]) || str[i] == '-') \
		&& str[i - 1] == ' ')
			return (err);
		i++;
	}
	return (ok);
}

int	main(int argc, char **argv)
{
	t_list	*first;
	t_list	**head;
	t_sort	s;

	first = NULL;
	head = &first;
	if (argc <= 1)
		return (0);
	if (argc == 2 && char_check(argv[1]) == err)
		wr_err("Error");
	else if (argc == 2 && single_arg_check(argv[1]) == ok)
		return (0);
	if (parser(input_to_string(argc, argv), head) != ok)
		wr_err("Error");
	if (indexer(head) != ok)
		wr_err("Error");
	s.total_inp = list_len(head);
	if (ft_pushswap(head, &s) != ok)
		wr_err("Error");
	return (0);
}
