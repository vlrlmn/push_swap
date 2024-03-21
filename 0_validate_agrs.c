/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_agrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:04:00 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/04 18:04:02 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_zero(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i] && num[i] == '0')
		i++;
	if (num[i])
		return (false);
	return (true);
}

int	nums_cmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

bool	is_double(char **num_arr, char *num, int index)
{
	int	i;

	i = 0;
	if (index == 0)
		return (0);
	while (i < index)
	{
		if ((nums_cmp(num_arr[i], num)) == 0)
			return (true);
		else
			i++;
	}
	return (false);
}

bool	is_num(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '-' || argv[i] == '+') && !argv[i + 1])
		return (0);
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	valid_nums(char **argv)
{
	int	i;
	int	zero_counter;

	i = 0;
	zero_counter = 0;
	if (!argv || !*argv)
		return (false);
	while (argv[i])
	{
		if (!is_num(argv[i]) || is_double(argv, argv[i], i))
			return (false);
		if (is_zero(argv[i]))
			zero_counter++;
		i++;
	}
	if (zero_counter > 1)
		return (false);
	return (true);
}
