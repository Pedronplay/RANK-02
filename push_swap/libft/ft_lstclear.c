/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:13:12 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/25 16:00:54 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmplst;
	t_list	*tmplst2;

	if (! *lst)
		return ;
	tmplst = *lst;
	while (tmplst)
	{
		tmplst2 = tmplst -> next;
		ft_lstdelone(tmplst, del);
		tmplst = tmplst2;
	}
	*lst = NULL;
}
