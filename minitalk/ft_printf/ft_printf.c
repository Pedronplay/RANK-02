/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:31:11 by pebarbos          #+#    #+#             */
/*   Updated: 2023/11/08 15:25:09 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_type(const char *specifier, va_list ap, int i)
{
	size_t	cont;

	cont = 0;
	if (specifier[i] == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (specifier[i] == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (specifier[i] == 'i' || specifier[i] == 'd')
		return (ft_print_base(va_arg(ap, int), 10, 's', cont));
	if (specifier[i] == 'u')
		return (ft_print_base(va_arg(ap, unsigned int), 10, 's', cont));
	if (specifier[i] == 'x')
		return (ft_print_base(va_arg(ap, unsigned int), 16, 'a', cont));
	if (specifier[i] == 'X')
		return (ft_print_base(va_arg(ap, unsigned int), 16, 'A', cont));
	if (specifier[i] == '%')
		return (ft_print_char('%'));
	if (specifier[i] == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long long), 16, 'a', cont));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		count;
	size_t		i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_print_type(format, ap, i);
		}
		else
			count += write(1, &format[i], 1);
		++i;
	}
	va_end(ap);
	return (count);
}
/*
# include <limits.h>
int	main(void)
{
	int	i;

	i = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("%i\n", i);
	i = ft_printf(" %p ", -1);
	printf("%i\n", i);
	i = printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("%i\n", i);
} */
