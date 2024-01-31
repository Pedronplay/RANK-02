/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:19:31 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/31 16:54:21 by pebarbos         ###   ########.fr       */
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
			if (args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]))
				return (0);
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
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	verify_dupl(char **args)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verify_args(char **args)
{
	if (verify_numbers(args) && verify_max(args) && verify_dupl(args))
		return (1);
	return (0);
}
