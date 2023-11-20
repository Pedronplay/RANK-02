/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:12:16 by pebarbos          #+#    #+#             */
/*   Updated: 2023/11/08 15:17:11 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long s, int n, char p, size_t cont)
{
	if (s == 0)
		return (ft_print_str("(nil)"));
	cont += ft_print_str("0x");
	if (s > (unsigned long long)n - 1)
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
	return (cont);
}
