/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:49:56 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/22 11:57:33 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	build_char(int sign, siginfo_t *info)
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
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

void	sign_handler(int bit, siginfo_t *info, void *content)
{
	(void)content;
	build_char(bit, info);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	build_char(0, NULL);
	ft_printf("SERVER PID: %d\n", pid);
	sa.sa_sigaction = &sign_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
}
