/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:02:57 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/18 10:29:20 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*frs1;
	unsigned char	*frs2;

	frs1 = (unsigned char *)str1;
	frs2 = (unsigned char *)str2;
	while (n && *frs1 == *frs2)
	{
		frs1++;
		frs2++;
		n--;
	}
	if (n)
		return (*frs1 - *frs2);
	else
		return (0);
}
