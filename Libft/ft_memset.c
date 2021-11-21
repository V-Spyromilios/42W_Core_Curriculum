/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* The memset() function writes len bytes of value c (converted to
* an unsigned char) to the string b.
*	RETURN
* The memset() function returns its first argument
*/

void 	*ft_memset(void *b, int c, size_t len)
{
	int		runner;
	char	*char_b;

	char_b = (char *)b;
	runner = len - 1;
	while (runner >= 0)
	{
		char_b[runner] = (unsigned char)c;
		runner--;
	}
	return (b);
}
