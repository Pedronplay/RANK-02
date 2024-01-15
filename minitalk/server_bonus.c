/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:49:56 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/15 13:03:27 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
	if ( sign == SIGUSR1)
		c |= (1 << i);
	write(1, &c, 1);
	i = 0;
	c = 0;
}

void	sign_handler(int bit)
{
	built_char(bit);
	signal(bit, sign_handler);
}

int	main(void)
{
	int pid;

	pid = getpid();
	build_char(0);
	ft_printf("SERVER PID: %d\n", pid);
	signal(SIGUSR1, sign_handler);
	signal(SIGUSR2, sign_handler);
	while (1)
	{
	}
}
