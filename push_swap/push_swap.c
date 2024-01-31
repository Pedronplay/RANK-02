/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:25 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/31 17:04:13 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (verify_args(++argv) == 1)
	{
		insert_to_stacks(&stack_a, argv);
		printdata(stack_a);
	}
	else
		ft_printf("Error");
}
