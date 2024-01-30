/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:25 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/30 15:36:15 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_args(char **args)
{
	if (verify_numbers(args) == 1 && verify_max(args) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	struct stack_a;
	struct stack_b;
	if (argc < 2)
	{
		(void)argv;
		ft_printf("Error\n");
		return (0);
	}
	else if (argc == 2)
		ft_split
	else if (verify_args(argv) == 1)
	{
		ft_printf("quase um sucesso");
		//	inset_to_stacks(argv);
	}
}
