#include "push_swap.h"

void	free_list(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		tmptmp = tmp->next;
		free(tmp);
		tmp = tmptmp;
	}
	head = NULL;
	return ;
}

short	node_back(t_list **head, t_list *node)
{
	t_list	*tmp;

	if (!node)
		return (err);
	if (!*head)
	{
		*head = node;
		return (ok);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	return (ok);
}

t_list	*new_node(int val)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->num = val;
	node->next = NULL;
	return (node);
}

t_list	*last_node(t_list **head)
{
	t_list	*tmp;
	
	if (!(head) || !(*head))
		return (NULL);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
