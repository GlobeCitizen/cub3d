/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:14:21 by mahnich           #+#    #+#             */
/*   Updated: 2019/12/06 15:54:27 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*lstmap;

	if (lst && f)
	{
		if ((lstmap = ft_lstnew(f(lst->content))))
		{
			element = lstmap;
			while (lstmap && (lst = lst->next))
			{
				if ((lstmap->next = ft_lstnew(f(lst->content))))
					lstmap = lstmap->next;
				else
				{
					ft_lstclear(&element, del);
					return (NULL);
				}
			}
			return (element);
		}
	}
	return (NULL);
}
