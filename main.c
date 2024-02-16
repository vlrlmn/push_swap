#include "push_swap.h"

int is_num(char *argv)
{
    int i;

    i = 0;
    if((argv[i] == '-' || argv[i] == '+') && argv[i + 1] != '\0')
        i++;
    else
        return(0);
    while(argv[i])
    {
        if (!ft_isdigit(argv[i]))
            return(0);
        i++;
    }
    return (1);
}

int valid_nums(char **argv)
{
    int i = 0;
    int zero_counter;

    i = 0;
    zero_counter = 0;
    while(argv[i])
    {
        if(!is_num(argv[i]) || is_double(argv[i], i))
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
    if (!valid_nums(argv))
        exit (1);
}