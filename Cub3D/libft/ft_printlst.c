/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:26:41 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/24 15:28:03 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Function used in Push Swap project. Prints the content of struct (int)
 * and the address. NOT part of Libft. Keep for future debug of linked lists..
 */
void	printlst(t_list *lst)
{
	while (lst)
	{
		printf("%d :  %p\n", lst->value, lst);
		lst = lst->next;
	}
}