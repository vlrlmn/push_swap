/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:20 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/12 12:04:21 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp->cur_position = i;
		tmp = tmp->next;
		i++;
	}
}

int	find_insert_pos(t_stack **a, int b_idx, int *min_pos_idx, int *min_idx)
{
	t_stack	*cpy_a;
	int		insert_pos;
	int		iterator;

	cpy_a = *a;
	insert_pos = -1;
	iterator = 0;
	while (cpy_a)
	{
		if (cpy_a->index > b_idx && cpy_a->index < *min_idx)
		{
			*min_idx = cpy_a->index;
			insert_pos = iterator;
		}
		else if (cpy_a->index > b_idx && insert_pos == -1)
			*min_pos_idx = iterator;
		cpy_a = cpy_a->next;
		iterator++;
	}
	if (insert_pos == -1 && *min_pos_idx == -1)
		insert_pos = iterator;
	return (insert_pos);
}

void	find_b_position_in_a(t_stack **a, t_stack **b)
{
	t_stack	*cpy_b;
	int		result;
	int		min_pos_idx;
	int		min_idx;

	cpy_b = *b;
	result = 0;
	if (!a || !b)
		return ;
	while (cpy_b)
	{
		min_pos_idx = -1;
		min_idx = INT_MAX;
		result = find_insert_pos(a, cpy_b->index, &min_pos_idx, &min_idx);
		if (result == -1)
			result = min_pos_idx;
		cpy_b->insert_position = result;
		cpy_b = cpy_b->next;
	}
}

// void	sort_b(t_stack **a, t_stack **b)
// {
// 	while (*b)
// 	{
// 		get_position(a);
// 		get_position(b);
// 		find_b_position_in_a(a, b);
// 		get_cost(a, b);
// 		do_cheapest_move(a, b);
// 	}
// }
