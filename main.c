#include "push_swap.h"
char **process_arguments(int argc, char **argv, int *need_free)
{
    char **split_argv = NULL;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        exit(1);
    else if (argc == 2)
    {
        split_argv = ft_split(argv[1], ' ');
        *need_free = 1; // Указываем, что память нужно будет освободить
    }
    else
    {
        split_argv = argv + 1; // Используем аргументы как есть
    }
    if (!valid_nums(split_argv))
        exit(1);

    return split_argv;
}

void perform_sorting(t_stack **a, t_stack **b, char **argv)
{
    fill_stack_a(a, b, argv);
    if (!stack_sorted(*a))
    {
        int len = stack_len(*a);
        if (len == 2)
            sa(a);
        else if (len == 3)
            sort_three(a);
        else
            sort_stacks(a, b, len);
    }
}

int main(int argc, char **argv)
{
    t_stack *a = NULL, *b = NULL;
    int need_free = 0; // Флаг для отслеживания необходимости освобождения памяти
    char **processed_argv = process_arguments(argc, argv, &need_free);

    perform_sorting(&a, &b, processed_argv);

    free_stack(&a);
    free_stack(&b);

    // Освобождение памяти, если использовался ft_split
    if (need_free)
    {
        for (int i = 0; processed_argv[i] != NULL; i++)
        {
            free(processed_argv[i]);
        }
        free(processed_argv);
    }

    return (0);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

	a = NULL;
	b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        exit(1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
    if (!valid_nums(argv + 1))
        exit (1);
	fill_stack_a(&a, &b, argv + 1);
	if(!stack_sorted(a))
	{
		if(stack_len(a) == 2)
			sa(&a);
		else if(stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b, stack_len(a));
	}
	free_stack(&a);
	free_stack(&b);
    return(0);
}
