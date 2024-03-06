/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:28 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/05 18:55:56 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		len;
	int		lowest_pos;

	len = stack_len(*a);
	lowest_pos = find_lowest_pos(a);
	if (lowest_pos > len / 2)
	{
		printf("Here 1\n");
		printf("len: %d\n", len);
		printf("len / 2: %d\n", len / 2);
		printf("lowest_pos: %d\n", lowest_pos);
		while (lowest_pos < len)
		{
			rra(a);
			printf("Here 1.1\n");
			lowest_pos++;
		}
	}
	else
	{
		printf("Here 2\n");
		printf("len: %d\n", len);
		printf("len / 2: %d\n", len / 2);
		printf("lowest_pos: %d\n", lowest_pos);
		while (lowest_pos > 0)
		{
			ra(a);
			lowest_pos--;
		}
	}
}
