/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 22:34:40 by jsauron           #+#    #+#             */
/*   Updated: 2018/04/14 16:59:09 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlist;
	t_list	*curr;

	if (lst != NULL && f != NULL)
	{
		nlist = f(lst);
		curr = nlist;
		while (lst->next)
		{
			lst = lst->next;
			curr->next = f(lst);
			curr = curr->next;
		}
		return (nlist);
	}
	return (NULL);
}
