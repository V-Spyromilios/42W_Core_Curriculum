/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:50:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/09/23 19:34:53 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
** Main Functions
*/
int		ft_printf(const char *, ...);
int		pc_found(char c, va_list args);
int		ft_char(va_list args);
int		ft_string(va_list args);
int		ft_pointer(va_list args);
int		ft_decimal(va_list args);
int		ft_integer(va_list args);
int		ft_un_decimal(va_list args);
int		ft_hexa_low(va_list args);
int		ft_hexa_caps(va_list args);
int		ft_percent(void);
/*
** Auxiliary Functions
*/
int		ft_strlen(const char *s);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnum_fd(int n, int fd);
int		find_int_len(int n);
int		find_int_len_16(unsigned long long n);
int		ft_putchar_fd(char c, int fd);
void	put_nbr(long int num, int base, char *base_char);
int		get_len(unsigned long int n);
void	write_buf(char *buffer, int length, unsigned long long int poi);
void	write_Hexa(char *buffer, int len, unsigned int num);
void	write_hexa(char *buffer, int len, unsigned int num);

#endif
