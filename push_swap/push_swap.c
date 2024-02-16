/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:25 by pebarbos          #+#    #+#             */
/*   Updated: 2024/02/16 16:21:02 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1 || argv[1][0] == '\0')
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	if (argv && verify_args(argv) == 1)
		insert_to_stacks(&stack_a, argv);
	else
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	stack_b = NULL;
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	printdata(stack_a);
	reverse_rotate(&stack_a);
	printdata(stack_a);
	printdata(stack_b);
}
