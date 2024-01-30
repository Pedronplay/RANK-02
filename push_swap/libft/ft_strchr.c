/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:31:08 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/16 11:01:56 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	fi;

	fi = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!fi)
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	char str[] = "este e o meu a teste";
	char a = 'a';

	printf("%s", strchr(str, a));
}*/
