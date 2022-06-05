/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:45:39 by espyromi          #+#    #+#             */
/*   Updated: 2021/06/18 15:09:18 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Params: The element to free. The address of
* the function used to delete the content. Takes as a
* parameter an element and frees the memory of the
* element’s content using the function
* ’del’ given as a parameter and free the element.
* The memory of ’next’ must not be freed.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
