/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:07:36 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/16 11:02:23 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	i;

	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	if (size < 1)
		return (s);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}
/*
#include <stdio.h>
int	main(void)
{
	char	dst[] = "coisas";
	char	src[] = "Banho de cao";
	size_t	n = 5;

	printf("%s\n", dst);
	ft_strlcpy(dst, src, n);
	printf("%s", dst);
}*/
