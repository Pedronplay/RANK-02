/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:32:38 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/06 10:56:04 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	i;
	int	s = 3;
	char	str[] = "Pedro";

	i = 0;

	ft_bzero(str, s);
	while (i < 5)
	{	
		if (str[i])
			printf("%c", str[i]);
		else
			printf("0");
		i++;
	}
}*/
