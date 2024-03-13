/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_calc_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:44 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/13 12:54:33 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_double_rotation(int b_rotations, int a_rotations)
{
	if (a_rotations > b_rotations)
		return (b_rotations);
	else
		return (a_rotations);
}

int	if_exceed_limits(t_stack **b, int node_a_index, int a_num)
{
	int	b_rotations;
	int	double_rotations;
	int	operations_count;

	operations_count = node_a_index + 1;
	double_rotations = 0;
	b_rotations = (*b)->index_of_min;
	double_rotations = calc_double_rotation(b_rotations, node_a_index);
	operations_count += b_rotations - double_rotations;
	return (operations_count);
}

int	if_not_exceed_limits(t_stack *b_node, t_stack *a_node, int node_a_index)
{
	int	b_rotations;
	int	operations_count;
	int	double_rotations;

	b_rotations = 0;
	operations_count = node_a_index + 1;
	while (b_node)
	{
		if (b_node->next && a_node->num > b_node->num
			&& a_node->num < b_node->next->num)
		{
			operations_count += b_rotations;
			break ;
		}
		b_rotations++;
		b_node = b_node->next;
	}
	double_rotations = calc_double_rotation(b_rotations, node_a_index);
	operations_count -= double_rotations;
	return (operations_count);
}

void	set_cost_in_a(t_stack *cur_a_node, int node_a_index, t_stack **b)
{
	t_stack	*cur_b_node;
	int		exceed_limits;
	int		operations_count;

	operations_count = 0;
	cur_b_node = *b;
	exceed_limits = is_num_exceed_limits(cur_a_node->num, b);
	if (exceed_limits)
	{
		operations_count = if_exceed_limits(b, node_a_index, cur_a_node->num);
	}
	else
	{
		operations_count = if_not_exceed_limits(cur_b_node, cur_a_node,
				node_a_index);
	}
	cur_a_node->cost_insert_a = operations_count;
}
