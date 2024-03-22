/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:08:48 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 13:05:11 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_stack **a, t_stack **b)
{
	t_stack	*a_cheapest;

	a_cheapest = (*a)->cheapest;
	if (a_cheapest->double_rotations)
		ra_rb_pb(a, b, a_cheapest);
	else if (a_cheapest->double_rev_rotations)
		rra_rrb_pb(a, b, a_cheapest);
	else
	{
		if (a_cheapest->a_rotations)
			do_ra(a, a_cheapest->a_rotations);
		if (a_cheapest->b_rotations)
			do_rb(b, a_cheapest->b_rotations);
		if (a_cheapest->a_rev_rotations)
			do_rra(a, a_cheapest->a_rev_rotations);
		if (a_cheapest->b_rev_rotations)
			do_rrb(b, a_cheapest->b_rev_rotations);
		pb(a, b);
	}
}

void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*head_a;

	head_a = *a;
	while (head_a && stack_len(head_a) > 3 && !(stack_sorted(*a)))
	{
		define_min_max(*b);
		set_cost_in_a(head_a, b);
		find_cheapest(a);
		push_node(a, b);
		head_a = *a;
	}
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*head_b;
	int		target_index;
	int		len_a;

	head_b = *b;
	while (head_b)
	{
		len_a = stack_len(*a);
		define_min_max(*a);
		target_index = get_target_index(a, (*b)->num);
		if (target_index == 0)
			pa(a, b);
		else if (target_index > (len_a / 2))
		{
			do_rra(a, len_a - target_index);
			pa(a, b);
		}
		else if (target_index <= (len_a / 2))
		{
			do_ra(a, target_index);
			pa(a, b);
		}
		head_b = *b;
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	if (stack_len(*a) > 3 && !stack_sorted(*a))
		pb(a, b);
	if (stack_len(*a) > 3 && !stack_sorted(*a))
		pb(a, b);
	if (stack_len(*a) >= 3 && !stack_sorted(*a))
		push_a_to_b(a, b);
	if (!(stack_sorted(*b)))
	{
		define_min_max(*b);
		if ((*b)->index_of_max <= (stack_len(*b) / 2))
			do_rb(b, (*b)->index_of_max);
		else
			do_rrb(b, stack_len(*b) - (*b)->index_of_max);
	}
	if (!stack_sorted(*a))
		sort_three(a);
	push_b_to_a(a, b);
}
