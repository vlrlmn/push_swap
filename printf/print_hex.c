/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:16:40 by vlomakin          #+#    #+#             */
/*   Updated: 2024/02/06 10:54:07 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_hex(unsigned long n, unsigned int base, char flag)
{
	int		count;
	char	*symbols;

	if (flag == 'x')
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n < base)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_hex((n / base), base, flag);
		return (count + print_hex((n % base), base, flag));
	}
}
