/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:01:00 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/30 10:47:47 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*node;
	t_list	*list;
	void	*content;

	list = NULL;
	while (lst)
	{
		content = f(lst -> content);
		node = ft_lstnew(content);
		if (!node || !content)
		{
			if (content && del)
				del(content);
			if (list)
				ft_lstclear(&list, del);
			if (node)
				free(node);
			return (0);
		}
		ft_lstadd_back(&list, node);
		lst = lst -> next;
	}
	return (list);
}
