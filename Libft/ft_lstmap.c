/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/19 18:44:21 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* Iterates the list ’lst’ and applies the function
* ’f’ to the content of each element.  Creates a new
* list resulting of the successive applications of
* the function ’f’.  The ’del’ function is used to
* delete the content of an element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*holder;

	if (!lst)
		return (NULL);
	holder = ft_lstnew(f(lst->content));
	if (!holder)
		return (NULL);
	new_list = holder;
	while (lst-> next)
	{
		lst = lst->next;
		holder = ft_lstnew(f(lst->content));
		ft_lstadd_back(&new_list, holder);
		holder = holder ->next;
		if (holder)
			ft_lstdelone(holder, del);
	}
	return (new_list);
}
