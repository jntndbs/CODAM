#include "push_swap.h"

void	print_values(t_list **head)
{
	// THIS FUNCTION IS JUST FOR TETSTING!!
	t_list	*tmp;

	tmp = *head;
	printf("Values:\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n\n");
	tmp = *head;
	printf("Index:\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->index);
		tmp = tmp->next;
	}
	printf("\n\n");
	return ;
}

t_list	*new_node(int val, int ind)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = val;
	node->index = ind;
	node->next = NULL;
	return (node);
}

void	parser(char *input, t_list **head)
{
	int		i;
	int		num;
	short	multiplier;

	i = 0;
	while (input[i])
	{
		if (input[i] <= '9' && input[i] >= '0')
		{
			multiplier = 1;
			if (i > 0 && input[i - 1] == '-')
				multiplier = -1;
			num = 0;
			while (input[i] <= '9' && input[i] >= '0')
			{
				num = num * 10 + (input[i] - '0');
				i++;
			}
			nodeadd_back(head, new_node(num * multiplier, 0));
		}
		i++;
	}
	return ;
}

void	indexer(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;
	int		i;

	tmp = *head;
	while (tmp != NULL)
	{
		i = 0;
		tmptmp = *head;
		while (tmptmp != NULL)
		{
			if (tmp->value > tmptmp->value)
				i++;
			tmptmp = tmptmp->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
	return ;
}

void	ft_pushswap(t_list **head_a)
{
	t_list	*first;
	t_list	**head_b;

	first = NULL;
	head_b = &first;
	if (!*head_a)
		return ;
	choose_action(head_a, head_b);// LEFTOFF
	return ;
}

int	main(void)
{
	char	input[] = "12 -23 34 45 11 67 32";
	t_list	*first;
	t_list	**head;
	t_var	var;

	first = NULL;
	head = &first;
	parser(input, head);
	indexer(head);
	var.inputsize = list_len(head);
	print_values(head);
	ft_pushswap(head);
	free_list(head);
	return (0);
}
