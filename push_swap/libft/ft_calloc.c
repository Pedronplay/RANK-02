/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:54:36 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/16 11:02:03 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmeb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmeb * size);
	return (ptr);
}
