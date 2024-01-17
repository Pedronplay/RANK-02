/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:28:01 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/16 10:11:30 by pebarbos         ###   ########.fr       */
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
			write(1, "\n", 1);
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	build_char(0);
	ft_printf("SERVER PID: %d\n", pid);
	signal(SIGUSR1, build_char);
	signal(SIGUSR2, build_char);
	while (1)
	{
	}
	return (0);
}
