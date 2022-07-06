/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:47:18 by espyromi          #+#    #+#             */
/*   Updated: 2021/12/01 18:56:46 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* c= char, s= string, p=pointer, d=int, i=signed decimal, 
* u= unsigned decimal int, x= hexa, X= hexa capitals, %= %
*/
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		i;

	i = 0;
	length = 0;
	va_start(args, format);
	if (!format[i])
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			length += ft_putchar_fd(format[i], 1);
		else
		{
			i++;
			length += pc_found(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (length);
}
