/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:23:17 by espyromi          #+#    #+#             */
/*   Updated: 2021/09/30 17:23:19 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pc_found(char c, va_list args)
{
	if (c == 'c')
		return (ft_char(args));
	else if (c == 's')
		return (ft_string(args));
	else if (c == 'p')
		return (ft_pointer(args));
	else if (c == 'd' || c == 'i')
		return (ft_decimal(args));
	else if (c == 'u')
		return (ft_un_decimal(args));
	else if (c == 'x')
		return (ft_hexa_low(args));
	else if (c == 'X')
		return (ft_hexa_caps(args));
	else if (c == '%')
	{
		ft_percent();
		return (1);
	}
	else
		return (0);
}

int	ft_char(va_list args)
{
	char	chr;

	chr = va_arg(args, int);
	return (write(1, &chr, 1));
}

int	ft_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		return (ft_putstr_fd(str, 1));
}

int	ft_pointer(va_list args)
{
	unsigned long long int	ptr;
	void					*address;
	char					*buf;
	int						len;

	address = va_arg(args, void *);
	if (!address)
	{
		write(1, "0x0", 3);
		return (3);
	}
	ptr = (unsigned long long int)address;
	len = find_int_len_16(ptr) + 3;
	buf = malloc((len) * sizeof(char));
	if (!buf)
		return (0);
	write_buf(buf, len, ptr);
	free(buf);
	return (--len);
}

int	ft_decimal(va_list args)
{
	long	number;
	int		length;

	number = va_arg(args, int);
	length = ft_putnum_fd(number, 1);
	return (length);
}
