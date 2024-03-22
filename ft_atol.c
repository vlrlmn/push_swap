/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:27:52 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/22 12:31:22 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_iswhitespaces(const int c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atol(char *str, t_stack **a)
{
	int			i;
	int			n;
	long long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] && ft_iswhitespaces(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		n = -1;
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if ((n == 1 && (result > INT_MAX)) || (n == -1
				&& ((-result < INT_MIN))))
			free_err1(a);
		i++;
	}
	return (result * n);
}
