/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:11:59 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/25 11:16:56 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstsize;

	lstsize = 0;
	while (lst != NULL)
	{
		lst = lst ->next;
		lstsize++;
	}
	return (lstsize);
}
