/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:28 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/07 16:17:54 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  Gets the current position of the element with the lowest index
*	within a stack */
int	find_lowest_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_idx;
	int		lowest_pos;

	tmp = *stack;
	lowest_idx = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->cur_position;
	while (tmp)
	{
		if (tmp->index < lowest_idx)
		{
			lowest_idx = tmp->index;
			lowest_pos = tmp->cur_position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	move_a(t_stack **a)
{
	int	len;
	int	lowest_pos;

	len = stack_len(*a);
	lowest_pos = find_lowest_pos(a);
	if (lowest_pos > len / 2)
	{
		while (lowest_pos < len)
		{
			rra(a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(a);
			lowest_pos--;
		}
	}
}
