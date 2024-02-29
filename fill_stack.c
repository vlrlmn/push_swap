#include "push_swap.h"

int create_node(t_stack **stack, int n)
{
	t_stack *node;
	t_stack *last_node;
	if(!stack)
		return (0);
	node = malloc(sizeof(t_stack));
	if(!node)
		return (0);
	node->next = NULL;
	node->num = n;
	if(!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return(1);
}

void fill_stack_a(t_stack **a, t_stack **b, char **argv)
{
    long int	n;
    int	i;
	int node_created;

	i = 0;
	while(argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_err(a, b);
		node_created = create_node(a, (int)n);
		if (!node_created)
			free_err(a, b);
		i++;
	}
}
