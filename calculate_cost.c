/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:17 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/11 13:03:17 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	calculate_cost_b(t_stack *b, int len_b)
{
	b->cost_top_b = b->cur_position;
	if (b->cur_position > len_b / 2)
		b->cost_top_b = (len_b - b->cur_position) * -1;
}

void	calculate_cost_a(t_stack *b, int len_a)
{
	b->cost_insert_a = b->insert_position;
	if (b->insert_position > len_a / 2)
		b->cost_insert_a = (len_a - b->insert_position) * (-1);
}

void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*cpy_b;
	int		len_a;
	int		len_b;

	len_a = stack_len(*a);
	len_b = stack_len(*b);
	cpy_b = *b;
	if (!a || !b)
		return ;
	while (cpy_b)
	{
		calculate_cost_b(cpy_b, len_b);
		calculate_cost_a(cpy_b, len_a);
		cpy_b = cpy_b->next;
	}
}
