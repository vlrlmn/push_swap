/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:34 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 12:19:19 by vlomakin         ###   ########.fr       */
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

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}
