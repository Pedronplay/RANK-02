/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:00:29 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/16 11:02:08 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	#include <stdio.h>
	printf("%d", ft_isdigit('0'));
	printf("%d", ft_isdigit('9'));
	printf("%d", ft_isdigit(' '));
	printf("%d", ft_isdigit('a'));
	printf("%d", ft_isdigit('Z'));
	printf("%d", ft_isdigit('5'));
}*/
