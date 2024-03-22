/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:05:36 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 12:05:56 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **processed_argv)
{
	int	i;

	i = 0;
	while (processed_argv[i])
	{
		free(processed_argv[i]);
		i++;
	}
	free(processed_argv);
}

void	free_stack(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*next;

	cur = *stack;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*stack = NULL;
}
