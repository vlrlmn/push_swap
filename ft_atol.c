#include "push_swap.h"

char	ft_iswhitespaces(const int c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atol(char *str)
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
			exit_with_err("Error\n");
		i++;
	}
	return (result * n);
}
