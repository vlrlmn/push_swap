/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:26 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 12:05:53 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_exit(char *msg)
{
	ft_printf(msg);
	exit(1);
}

void	free_err1(t_stack **a)
{
	if (a != NULL && *a != NULL)
		free_stack(a);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

void	free_err(t_stack **a, t_stack **b)
{
	if (a != NULL)
		free_stack(a);
	if (b != NULL && *b != NULL)
		free_stack(b);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

void	exit_with_err(char *msg, char **args)
{
	ft_printf(msg);
	free_argv(args);
	exit(1);
}
