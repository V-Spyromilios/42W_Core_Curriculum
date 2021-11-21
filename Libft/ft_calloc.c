/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	The calloc() function contiguously allocates enough space for count
*	objects that are size bytes of memory each and returns a pointer to
*	the allocated memory. The allocated memory is filled with
*	bytes of value zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*storage;

	storage = malloc(size * count);
	if (!storage)
		return (NULL);
	ft_memset(storage, 0, size * count);
	return (storage);
}
