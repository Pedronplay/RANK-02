/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:06:35 by pebarbos          #+#    #+#             */
/*   Updated: 2023/11/08 15:10:00 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_base(long int s, int n, char p, size_t cont)
{
	if (s < 0)
	{
		s *= -1;
		ft_print_char('-');
		cont++;
	}
	if (s > (long int)n - 1)
	{
		cont = ft_print_base(s / n, n, p, cont);
		cont = ft_print_base(s % n, n, p, cont);
	}
	if ((p == 'a' || p == 'A') && s < 16)
	{
		if (s <= 9)
			cont += ft_print_char(s + '0');
		else
			cont += ft_print_char(s + p - 10);
	}
	if (s <= 9 && p == 's')
	{
		ft_print_char(s + '0');
		cont++;
	}
	return (cont);
}
