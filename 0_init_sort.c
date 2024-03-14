/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinode_avaleria <lomakinode_avaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:53 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/14 13:03:00 by lomakinode_aval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cheapest(t_stack **a)
{
	t_stack	*node_a;

	node_a = *a;
	while (node_a)
	{
		if (node_a->next && node_a->cost_to_push_a > node_a->next->cost_to_push_a)
		{
			node_a->cheapest = node_a->next;
			break ;
		}
		node_a = node_a->next;
	}
}

void	push_node(t_stack *a, t_stack **b, t_stack *a_cheapest)
{
    if(a->a_rotations == 0 && a->b_rotations == 0)
        pb(&a, b);
    if(a->a_rotations && a->b_rotations == 0)
        ra_pb(&a, b, a_cheapest);
    if(a->a_rotations == 0 && a->b_rotations)
        rb_pb(&a, b, a_cheapest);
	if (a->a_rotations && a->b_rotations)
        ra_rb_pb(&a, b, a_cheapest);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node_a;

	node_a = *a;
	while(node_a)
	{
		set_cost_in_a(node_a, b);
		find_cheapest(a);
		push_node((*a), b, (*a)->cheapest);
		node_a = node_a->next;
	}
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

void push_back(t_stack **a, t_stack **b)
{
	t_stack *b_node = *b;
	while(b_node)
	{
		pb(a, b);
		b_node = b_node->next;
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	push_a_to_b(a, b);
	push_back(a, b);
}
