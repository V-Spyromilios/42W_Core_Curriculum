/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:18:36 by espyromi          #+#    #+#             */
/*   Updated: 2021/09/30 17:21:11 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum_fd(int n, int fd)
{
	int	len;

	len = find_int_len(n);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnum_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return (len);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}

void	write_buf(char *buffer, int length, unsigned long long int poi)
{
	int		rs;
	int		i;

	buffer[0] = '0';
	buffer[1] = 'x';
	length = find_int_len_16(poi) + 3;
	buffer[length - 1] = '\0';
	i = length - 2;
	while (poi >= 0 && i > 1)
	{
		rs = poi % 16;
		buffer[i] = "0123456789abcdef"[rs];
		i--;
		poi = poi / 16;
	}
	write(1, buffer, ft_strlen(buffer));
}

void	write_hexa_c(char *buffer, int len, unsigned int num)
{
	int	pos;
	int	i;

	buffer[len - 1] = '\0';
	i = len - 2;
	while (num >= 0 && i >= 0)
	{
		pos = num % 16;
		buffer[i] = "0123456789ABCDEF"[pos];
		i--;
		num = num / 16;
	}
	write(1, buffer, ft_strlen(buffer));
}

void	write_hexa(char *buffer, int len, unsigned int num)
{
	int	pos;
	int	i;

	buffer[len - 1] = '\0';
	i = len - 2;
	while (num >= 0 && i >= 0)
	{
		pos = num % 16;
		buffer[i] = "0123456789abcdef"[pos];
		i--;
		num = num / 16;
	}
	write(1, buffer, ft_strlen(buffer));
}
