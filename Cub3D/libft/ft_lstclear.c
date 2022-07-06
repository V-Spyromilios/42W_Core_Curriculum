/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:36:09 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/19 19:13:06 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*  Deletes and frees the given element and every
*  successor of that element, using the function ’del’
*  and free(). Finally, the pointer to the list must be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		del(current->content);
		current = current->next;
		free(*lst);
		*lst = current;
	}
	lst = NULL;
}
