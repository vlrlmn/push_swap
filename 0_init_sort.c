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
    t_stack	*head_a;

	node_a = *a;
	head_a = *a;
	head_a->cheapest = node_a;
	while (node_a)
	{
		if (node_a->next && head_a->cheapest->cost_to_push_a > node_a->next->cost_to_push_a)
		{
			head_a->cheapest = node_a->next;
			break ;
		}
		node_a = node_a->next;
	}
}

void	push_node(t_stack **a, t_stack **b)
{
    t_stack *a_cheapest;

	a_cheapest = (*a)->cheapest;
	if(a_cheapest->a_rotations == 0 && a_cheapest->b_rotations == 0)
        pb(a, b);
    else if(a_cheapest->a_rotations && a_cheapest->b_rotations == 0)
        ra_pb(a, b, a_cheapest);
    else if(a_cheapest->a_rotations == 0 && a_cheapest->b_rotations)
        rb_pb(a, b, a_cheapest);
	else if (a_cheapest->a_rotations && a_cheapest->b_rotations)
        ra_rb_pb(a, b, a_cheapest);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*head_a;

	head_a = *a;
	while(head_a)
	{
		define_min_max(*b);
		set_cost_in_a(head_a, b);
		find_cheapest(a);
		push_node(a, b);
		head_a = *a;
	}
}

void	push_a_to_b(t_stack **a, t_stack **b)
{
	if (stack_len(*a) > 3 && !stack_sorted(*a))
		pb(a, b);
	if (stack_len(*a) > 3 && !stack_sorted(*a))
		pb(a, b);
	if (stack_len(*a) >= 3 && !stack_sorted(*a))
		push_to_b(a, b);
	if (!stack_sorted(*a))
		sort_three(a);
}


void	big_sort(t_stack **a, t_stack **b)
{
	push_a_to_b(a, b);
	while(*b)
		pa(a, b);
	while(!stack_sorted(*a))
		ra(a);
}

