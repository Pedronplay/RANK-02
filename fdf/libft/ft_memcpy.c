/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:56:46 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/18 10:18:30 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*a_src;
	unsigned char		*a_dest;

	i = 0;
	a_src = (unsigned char *)src;
	a_dest = (unsigned char *)dest;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		a_dest[i] = a_src[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	size_t	i = 11;
	char src[] = "Muita coisa escrita";
	char dest[30] = "";
	printf("%s", dest);
	memcpy(dest, src, i);
	printf("%s", dest);
}*/
