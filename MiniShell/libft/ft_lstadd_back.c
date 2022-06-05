/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:04:57 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/19 18:49:25 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* Adds the element ’new’ at the end of the list.
* Params: The address of a pointer to the first link of
* a list.The address of a pointer to the element to be
* added to the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*holder;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			holder = ft_lstlast(*(lst));
			holder->next = new;
		}
	}
}
