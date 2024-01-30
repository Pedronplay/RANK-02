/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:19:31 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/30 15:22:24 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_numbers(char **args)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			ft_printf("DAAMMM");
			if (args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]))
			{
				ft_printf("PUMBA");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	verify_max(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (ft_atoi(args[i]) > INT_MAX || ft_atoi(args[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
