/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:46 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/14 18:06:11 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

int	stack_len(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	create_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return (0);
	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->next = NULL;
	node->num = n;
	node->cur_position = -1;
	node->insert_position = -1;
	node->cost_to_push_a = -1;
	node->a_rotations = 0;
	node->b_rotations = 0;
	node->index = 0;
	node->max_num = INT_MAX;
	node->min_num = INT_MIN;
	if (!(*stack))
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
	return (1);
}

void	fill_stack_a(t_stack **a, char **argv)
{
	long int	n;
	int			i;
	int			node_created;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_err1(a);
		node_created = create_node(a, (int)n);
		if (!node_created)
			free_err1(a);
		i++;
	}
}
