/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:30:47 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/16 15:20:15 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
		ft_printf("Message sent successfuly\n");
	else
		ft_printf("Something strange is happening\n");
	exit(EXIT_SUCCESS);
}

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
}

int	main(int argc, char **argv)
{
	static int	pid;

	if (argc != 3)
	{
		ft_printf("Correct format is ./client <SERVER_PID> <MESSAGE>");
		return (1);
	}
	signal(SIGUSR1, signal_handler);
	pid = ft_atoi(argv[1]);
	while (*argv[2])
		send_to_server(pid, *argv[2]++);
	send_to_server(pid, *argv[2]);
	while (1)
	{
		pause();
	}
	return (0);
}
