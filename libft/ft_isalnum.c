/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:12:11 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/16 11:02:05 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	#include<stdio.h>
	printf("%d", ft_isalnum('0'));
	printf("%d", ft_isalnum('9'));
	printf("%d", ft_isalnum(' '));
	printf("%d", ft_isalnum('Z'));
	printf("%d", ft_isalnum('/'));
	printf("%d", ft_isalnum('a'));
}*/
