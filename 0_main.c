/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:30 by vlomakin          #+#    #+#             */
/*   Updated: 2024/03/21 16:05:11 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_exit(char *msg)
{
	ft_printf(msg);
	exit(1);
}
void	perform_sorting(t_stack **a, t_stack **b, char **argv)
{
	int	len;

	if (argv[0] == NULL)
		finish_exit("Error\n");
	fill_stack_a(a, argv);
	if (!stack_sorted(*a))
	{
		len = stack_len(*a);
		if (len == 2)
			sa(a);
		else if (len == 3)
			sort_three(a);
		else
			big_sort(a, b);
	}
}

char	**process_args(int argc, char **argv, int *need_free)
{
	char	**split_argv;

	split_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(0);
	else if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		*need_free = 1;
		if (!split_argv)
			finish_exit("Error\n");
		if (!valid_nums(split_argv))
			exit_with_err("Error\n", split_argv);
	}
	else
	{
		split_argv = argv + 1;
		*need_free = 0;
		if(!valid_nums(split_argv))
			finish_exit("Error\n");
	}
	return (split_argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		need_free;
	char	**processed_argv;

	need_free = 0;
	processed_argv = process_args(argc, argv, &need_free);
	a = NULL;
	b = NULL;
	perform_sorting(&a, &b, processed_argv);
	free_stack(&a);
	free_stack(&b);
	if (need_free)
		free_argv(processed_argv);
}
