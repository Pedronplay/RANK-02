/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:27:33 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/24 11:19:10 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getsize(long int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		size;
	long int	num;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	size = ft_getsize(num);
	if (num < 0)
		num *= -1;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[size--] = '\0';
	while (num >= 1)
	{
		str[size] = (num % 10) + '0';
		num = num / 10;
		size--;
	}
	return (str);
}
/*
int main(void)
{	
	char *s;

	s = ft_itoa(0);
	printf("%s", s);
}*/
