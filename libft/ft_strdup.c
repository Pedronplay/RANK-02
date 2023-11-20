/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:09:06 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/16 15:03:49 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	i = ft_strlen(s);
	str = (char *)malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s[len])
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
