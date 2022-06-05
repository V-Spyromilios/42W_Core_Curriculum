/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/19 18:16:36 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* Allocates (with malloc(3)) and returns a new element.
* The variable ’content’ is initialized with the value of the
* parameter ’content’.  The variable ’next’ is initialized to NULL.
* Returns the new element.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*instance;

	instance = (t_list *)malloc(sizeof(t_list));
	if (!instance)
		return (NULL);
	instance->content = content;
	instance->next = NULL;
	return (instance);
}
