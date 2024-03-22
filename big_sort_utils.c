/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:48 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 12:35:07 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num_exceed_limits(int number, t_stack **b)
{
	return ((number > (*b)->max_num) || (number < (*b)->min_num));
}

int	target_index_in_limits(t_stack **a, int num)
{
	t_stack	*stack;
	int		index;
	int		target_index;
	int		diff;
	int		current_diff;

	index = 0;
	target_index = 0;
	stack = *a;
	diff = INT_MAX;
	while (stack)
	{
		current_diff = stack->num - num;
		if (current_diff > 0 && current_diff < diff)
		{
			target_index = index;
			diff = current_diff;
		}
		index++;
		stack = stack->next;
	}
	return (target_index);
}

int	get_target_index(t_stack **a, int num)
{
	if (is_num_exceed_limits(num, a) == 1)
		return ((*a)->index_of_min);
	else
		return (target_index_in_limits(a, num));
}

void	find_cheapest(t_stack **a)
{
	t_stack	*node_a;
	t_stack	*head_a;

	node_a = *a;
	head_a = *a;
	head_a->cheapest = node_a;
	while (node_a)
	{
		if (node_a->next
			&& head_a->cheapest->cost_to_push_a > node_a->next->cost_to_push_a)
		{
			head_a->cheapest = node_a->next;
		}
		node_a = node_a->next;
	}
}

void	define_min_max(t_stack *head)
{
	t_stack	*node;

	get_position(&head);
	head->min_num = head->num;
	head->index_of_min = head->cur_position;
	head->max_num = head->num;
	head->index_of_max = head->cur_position;
	node = head;
	while (node)
	{
		if (node->num > head->max_num)
		{
			head->index_of_max = node->cur_position;
			head->max_num = node->num;
		}
		else if (node->num < head->min_num)
		{
			head->index_of_min = node->cur_position;
			head->min_num = node->num;
		}
		node = node->next;
	}
}
