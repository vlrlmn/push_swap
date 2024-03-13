/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:53 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/13 16:29:45 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_cheapest(t_stack **a)
{
	t_stack	*node_a;
	t_stack	*cheapest;

	node_a = *a;
	cheapest = node_a;
	while (node_a)
	{
		if (node_a->next && node_a->cost_insert_a > node_a->next->cost_insert_a)
		{
			cheapest = node_a->next;
			break ;
		}
		node_a = node_a->next;
	}
	return (cheapest);
}

void	set_insert_position(t_stack *src, t_stack **dst)
{
	t_stack	*dst_node;

	dst_node = *dst;
	while (dst_node)
	{
		if (src->num > dst_node->max_num || src->num < dst_node->min_num)
			src->insert_position = 0;
		else if (dst_node->next && src->num < dst_node->num
				&& src->num > dst_node->next->num)
			src->insert_position = dst_node->next->cur_position;
		dst_node = dst_node->next;
	}
}
void	push_node(t_stack *src, t_stack **dst)
{
	if(is_num_exceed_limits(src->num, dst) && )
	{
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*current_a_node;
	t_stack	*cheapest;
	int		index;

	index = 0;
	current_a_node = *a;
	while (current_a_node)
	{
		set_cost_in_a(current_a_node, index, b);
		current_a_node = current_a_node->next;
		index++;
	}
	cheapest = find_cheapest(a);
	set_insert_position(cheapest, b);
	push_node(cheapest, b);
}

void	push_a_to_b(t_stack **a, t_stack **b)
{
	if (stack_len(*a) > 3 && !stack_sorted(*a))
		pb(a, b);
	if (stack_len(*a) > 3 && !stack_sorted(*a))
		pb(a, b);
	define_min_max(*b);
	if (stack_len(*a) > 3 && !stack_sorted(*a))
		push_to_b(a, b);
	if (!stack_sorted(*a))
		sort_three(a);
}

void	big_sort(t_stack **a, t_stack **b)
{
	push_a_to_b(a, b);
}
