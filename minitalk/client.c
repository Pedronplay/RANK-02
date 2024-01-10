/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 04:15:55 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/10 00:39:50 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_to_server(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
	usleep(50);
}

int	main(int argc, char **argv)
{
	static int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	while (*argv[2])
		send_to_server(pid, *argv[2]++);
	send_to_server(pid, *argv[2]);
	return (0);
}
