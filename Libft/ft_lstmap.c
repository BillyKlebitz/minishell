/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:22:49 by suzumaki          #+#    #+#             */
/*   Updated: 2021/05/22 00:04:35 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!(res))
		return (NULL);
	node = res;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		if (!(node->next))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	return (res);
}
