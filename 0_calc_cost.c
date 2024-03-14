/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_calc_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:44 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/14 17:45:37 by lomakinaval      ###   ########.fr       */
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

int	if_exceed_limits(t_stack **b_stack, t_stack *a, int a_rots)
{
	t_stack *b;
	int	operations_count;

	b = *b_stack;
	operations_count = a_rots + 1;
	a->double_rotations = 0;
	a->b_rotations = b->index_of_max;
	a->double_rotations = double_rots(a_rots, a->b_rotations);
	operations_count += a->b_rotations - a->double_rotations;
	return (operations_count);
}

int	if_not_exceed_limits(t_stack **b_stack, t_stack *a, int a_rots)
{
	t_stack *b = *b_stack;
	int	operations_count;
	int	double_rotations;

	a->b_rotations = 0;
	operations_count = a_rots + 1;
	while (b)
	{
		if (b->next && a->num > b->num
			&& a->num < b->next->num)
		{
			operations_count += a->b_rotations;
			break ;
		}
		a->b_rotations++;
		b = b->next;
	}
	double_rotations = double_rots(a->b_rotations, a_rots);
	operations_count -= double_rotations;
	return (operations_count);
}


void	set_cost_in_a(t_stack *a, t_stack **b)
{
	int		exceed_limits;
	int		operations_count;
	int index;

	operations_count = 0;
	index = 0;
	while(a)
	{
		a->a_rotations = index;
		exceed_limits = is_num_exceed_limits(a->num, b);
		if (exceed_limits)
		{
			operations_count = if_exceed_limits(b, a, a->a_rotations);
		}
		else
		{
			operations_count = if_not_exceed_limits(b, a, a->a_rotations);
		}
		index++;
		a->cost_to_push_a = operations_count;
		a = a->next;
	}
}
