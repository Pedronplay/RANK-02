/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:19:31 by pebarbos          #+#    #+#             */
/*   Updated: 2024/02/26 16:17:45 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_numbers(char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] == '-') || args[i][j] == '+')
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
	if (args == NULL || args[0] == NULL)
		return (0);
	if (verify_numbers(args) && verify_max(args) && verify_dupl(args))
		return (1);
	return (0);
}

void	free_stack(t_stack *stack) 
{
	t_stack *temp;
	while (stack != NULL) 
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}