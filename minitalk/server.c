/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:28:01 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/10 00:42:41 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (octet & i)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i >>= 1;
	}
}

void	build_char(int sign)
{
	static int	i;
	static int	c;

	if (sign != SIGUSR1 && sign != SIGUSR2)
	{
		i = 0;
		c = 0;
		return ;
	}
	if (sign == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
//		print_bits(c);
		if (c == 0)
			write(1, "/n", 1);
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	sign_handler(int bit)
{
	build_char(bit);
	signal(bit, sign_handler);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	build_char(0);
	ft_printf("SERVER PID: %d\n", pid);
	signal(SIGUSR1, sign_handler);
	signal(SIGUSR2, sign_handler);
	while (1)
	{
	}
	return (0);
}
