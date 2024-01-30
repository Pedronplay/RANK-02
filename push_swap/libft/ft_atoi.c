/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:24:29 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/30 11:41:32 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sin;
	int		res;
	char	*s;

	s = (char *)nptr;
	i = 0;
	sin = 1;
	res = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
	{
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sin *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (res * sin);
}
