#include "push_swap.h"
int is_zero(char *num)
{
	int i;

	i = 0;
	if(num[i] == '-' || num[i] == '+')
		i++;
	while(num[i] && num[i] == '0')
		i++;
	if(num[i])
		return(0);
	return(1);
}

int nums_cmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if(s1[i] == '+')
	{
		if(s2[j] != '+')
			i++;
	}
	else
	{
		if(s2[j] == '+')
			j++;
	}
	while(s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	is_double(char **num_arr, char *num, int index)
{
	int	i;

	i = 0;
	if (index == 0)
		return(0);
    while(i < index)
    {
		if((nums_cmp(num_arr[i], num)) == 0)
		{
			ft_printf(RED BOLD"There are duplicates\n" RESET);
			return(1);
		}
		else
			i++;
    }
    return (0);
}

int is_num(char *argv)
{
    int i;
	
	i = 0;
    if((argv[i] == '-' || argv[i] == '+') && !argv[i + 1])
        return(0);
    if(argv[i] == '-' || argv[i] == '+')
        i++;
    while(argv[i])
    {
        if (!ft_isdigit(argv[i]))
		{
			ft_printf(RED BOLD"There are not numbers\n" RESET);
            return(0);
		}
        i++;
    }
    return (1);
}

int valid_nums(char **argv)
{
    int i;
    int zero_counter;

    i = 0;
    zero_counter = 0;
    while(argv[i])
    {
        if(!is_num(argv[i]) || is_double(argv, argv[i], i))
            return(0);
        if (is_zero(argv[i]))
            zero_counter++;
        i++;
    }
    if (zero_counter > 1)
        return(0);
    return(1);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);
    if (!valid_nums(argv + 1))
        exit (1);
	// a = fill_stack_a(argc, argv);
    printf("Valid nums\n");
}