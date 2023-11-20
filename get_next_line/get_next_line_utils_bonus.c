/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:06:51 by pebarbos          #+#    #+#             */
/*   Updated: 2023/11/20 15:07:47 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n)
	{
		*p++ = 0;
		--n;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	fi;

	fi = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == (unsigned char) c)
			return ((char *)s);
		s++;
	}
	if (!fi)
		return ((char *)s);
	return (NULL);
}
