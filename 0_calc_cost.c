/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_calc_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:44 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/19 21:40:47 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_rots(int a_rotations, int b_rotations)
{
	if (a_rotations > b_rotations)
		return (b_rotations);
	else
		return (a_rotations);
}

void define_cheapest_instructions(t_stack *a)
{
	int	rot_rev_count;
	int	rev_rot_count;
	int	rot_rot_count;
	int	rev_rev_count;

	rot_rot_count = 1 + a->a_rotations + a->b_rotations - a->double_rotations;
	rot_rev_count = 1 + a->a_rotations + a->b_rev_rotations;
	rev_rot_count = 1 + a->a_rev_rotations + a->b_rotations;
    rev_rev_count = 1 + a->a_rev_rotations + a->b_rev_rotations
						- a->double_rev_rotations;
	if (rot_rot_count <= rot_rev_count && rot_rot_count <= rev_rot_count
				&& rot_rot_count <= rev_rev_count)
		rot_rot_instruction(a, rot_rot_count);
	else if (rot_rev_count <= rot_rot_count && rot_rev_count <= rev_rot_count
				&& rot_rev_count <= rev_rev_count)
		rot_rev_instruction(a, rot_rev_count);
	else if (rev_rot_count <= rot_rot_count && rev_rot_count <= rot_rev_count
				&& rev_rot_count <= rev_rev_count)
		rev_rot_instruction(a, rev_rot_count);
	else
		rev_rev_instruction(a, rev_rev_count);
}

int find_rot(t_stack *stack, int num)
{
	int rotations;
	int found_bigger;
	
	rotations = 0;
	found_bigger = 0;
	while (stack)
	{
		if (num < stack->num)
		{
			found_bigger = 1;
			if (!(stack)->next)
			{
				rotations = 0;
				break;
			}
		}
		else if (num > stack->num && found_bigger == 1)
			break;
		rotations++;
		stack = stack->next;
	}
	return rotations;
}


void calc_b_rotations(t_stack *b, t_stack *a)
{
	if (is_num_exceed_limits(a->num, &b) == 1)
		a->b_rotations = b->index_of_max;
	else
		a->b_rotations = find_rot(b, a->num);
}

void	calc_cost_for_node(t_stack **b_stack, t_stack *a, int len_a, int a_index)
{
	t_stack *b;

	b = *b_stack;
    a->a_rotations = a_index;
    a->a_rev_rotations = len_a - a_index;
	a->b_rotations = 0;
	calc_b_rotations(b, a);
	a->b_rev_rotations = stack_len(b) - a->b_rotations;
	a->double_rotations = double_rots(a->a_rotations, a->b_rotations);
	a->double_rev_rotations = double_rots(a->a_rev_rotations, a->b_rev_rotations);
	define_cheapest_instructions(a);
}

void	set_cost_in_a(t_stack *a, t_stack **b)
{
	int index;
	int len_a;

	index = 0;
	len_a = stack_len(a);
	while(a)
	{
		calc_cost_for_node(b, a, len_a, index);
		index++;
		a = a->next;
	}
}
