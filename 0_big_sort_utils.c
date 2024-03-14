/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_big_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:48 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/14 17:47:28 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num_exceed_limits(int number, t_stack **b)
{
	return ((number > (*b)->max_num) || (number < (*b)->min_num));
}

void	define_min_max(t_stack *stack)
{
	get_position(&stack);
	stack->min_num = stack->num;
	stack->max_num = stack->num;
	while (stack)
	{
		if (stack->num > stack->max_num)
		{
			stack->index_of_max = stack->cur_position;
			stack->max_num = stack->num;
		}
		else if (stack->num < stack->min_num)
		{
			stack->index_of_min = stack->cur_position;
			stack->min_num = stack->num;
		}
		stack = stack->next;
	}
}