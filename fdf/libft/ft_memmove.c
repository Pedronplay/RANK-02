/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:27:53 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/09 12:34:00 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a_dest;
	unsigned char	*a_src;

	i = 0;
	a_dest = (unsigned char *)dest;
	a_src = (unsigned char *)src;
	if (a_dest == a_src)
		return (dest);
	if (a_dest < a_src)
	{
		while (i < n)
		{
			a_dest[i] = a_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			a_dest[i] = a_src[i];
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
	ft_memmove(dest, src, i);
	printf("%s", dest);
}*/
