/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* The strdup function allocates sufficient memory for a copy of the string s1,
* does the copy, and returns a pointer to it.  The pointer may subsequently be
* used as an argument to the function free().
* If insufficient memory is available, NULL is returned
* and errno is set to ENOMEM.
* The strndup function copies at most n characters from the string s1
* always NUL terminating the copied string.
*/

char	*ft_strdup(const char *s1)
{
	int		counter;
	char	*storage;
	char	*runner;

	counter = 0;
	runner = (char *)s1;
	while (*runner)
	{
		counter++;
		runner++;
	}
	storage = malloc((sizeof(char) * (counter + 1)));
	if (!storage)
		return (NULL);
	counter = 0;
	while (s1[counter] != '\0')
	{
		storage[counter] = s1[counter];
		counter++;
	}
	storage[counter] = '\0';
	return (storage);
}
