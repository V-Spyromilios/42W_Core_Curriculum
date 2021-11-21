/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:47:27 by espyromi          #+#    #+#             */
/*   Updated: 2021/09/30 17:22:22 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_un_decimal(va_list args)
{
	unsigned int	length;
	unsigned long	number;

	number = va_arg(args, unsigned int);
	length = get_len(number);
	put_nbr((unsigned long) number, 10, "0123456789");
	return (length);
}

int	get_len(unsigned long int n)
{
	int	length;

	length = 1;
	while (n > 9)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

void	put_nbr(long int num, int base, char *base_char)
{
	int	index;

	if (num / base)
		put_nbr(num / base, base, base_char);
	index = num % base;
	write(1, &base_char[index], 1);
}

int	ft_hexa_low(va_list args)
{
	unsigned int	nbr;
	char			*buf;
	int				lenn;

	nbr = va_arg(args, unsigned int);
	if (!nbr)
	{
		write(1, "0", 1);
		return (1);
	}
	lenn = find_int_len_16(nbr) + 1;
	buf = malloc((lenn) * sizeof(char));
	if (!buf)
		return (0);
	write_hexa(buf, lenn, nbr);
	free(buf);
	return (--lenn);
}

int	ft_hexa_caps(va_list args)
{
	unsigned int	nbr;
	char			*buf;
	int				lenn;

	nbr = va_arg(args, unsigned int);
	if (!nbr)
	{
		write(1, "0", 1);
		return (1);
	}
	lenn = find_int_len_16(nbr) + 1;
	buf = malloc((lenn) * sizeof(char));
	if (!buf)
		return (0);
	write_hexa_c(buf, lenn, nbr);
	free(buf);
	return (--lenn);
}
