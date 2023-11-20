/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:10 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/24 16:27:54 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}
/*
int main(void)
{
    t_list *node = ft_lstnew("hello world");

    if (node != NULL)
    {
        printf("Content: %s\n", (char *)node->content);
        free(node);
    }
    else
    {
        printf("Error: Unable to create a new node.\n");
    }
    return 0;
}
*/
