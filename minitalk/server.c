/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:28:01 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/09 06:28:58 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
