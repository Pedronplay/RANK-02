/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:50:44 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/16 11:02:06 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%d", ft_isalpha('a'));
	printf("%d", ft_isalpha('z'));
	printf("%d", ft_isalpha('A'));
	printf("%d", ft_isalpha('Z'));
	printf("%d", ft_isalpha('1'));
}*/
