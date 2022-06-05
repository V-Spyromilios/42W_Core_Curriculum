/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Applies the function ’f’ to each character of the
*	string ’s’ to create a new string (with malloc(3))
*	resulting from successive applications of ’f’. Returns the string or Null.
*/

char 	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*allocation;
	unsigned int	counter;
	int				length;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	allocation = (char *)malloc((length + 1) * sizeof(char));
	if (!allocation)
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		allocation[counter] = f(counter, s[counter]);
		counter++;
	}
	allocation[counter] = '\0';
	return (allocation);
}
