/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_big_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:48 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/15 15:10:38 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num_exceed_limits(int number, t_stack **b)
{
	return ((number > (*b)->max_num) || (number < (*b)->min_num));
}

void	define_min_max(t_stack *head)
{
	get_position(&head);
	head->min_num = head->num;
	head->index_of_min = head->cur_position;
	head->max_num = head->num;
    head->index_of_max = head->cur_position;
		
	t_stack *node = head;
	while (node)
	{
		if (node->num > head->max_num)
		{
			head->index_of_max = node->cur_position;
			head->max_num = node->num;
		}
		else if (node->num < head->min_num)
		{
			head->index_of_min = node->cur_position;
			head->min_num = node->num;
		}
		node = node->next;
	}
}