/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:56 by pebarbos          #+#    #+#             */
/*   Updated: 2024/04/05 16:29:09 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	in;
	size_t	fi;

	if (!s1 || !set)
		return (NULL);
	in = 0;
	fi = ft_strlen(s1);
	while (ft_strchr(set, s1[in]) && s1[in])
		in++;
	while (ft_strchr(set, s1[fi]) && fi > in)
		fi--;
	str = ft_substr(s1, in, (fi - in) + 1);
	if (!str)
		return (NULL);
	return (str);
}
