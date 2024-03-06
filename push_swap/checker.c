/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:54:31 by pedronplay        #+#    #+#             */
/*   Updated: 2024/03/06 15:04:31 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !process_args(argc, argv, &stack_a) || argv[1] == NULL)
		return (EXIT_FAILURE);
	if (sorted(&stack_a))
	{
		free_stack(stack_a);
		return (EXIT_SUCCESS);
	}
	get_instructions(&stack_a, &stack_b);
	if (stack_b != NULL || !sorted(&stack_a))
		write(2, "KO\n", 3);
	else
		ft_printf("OK\n");
	free_stack(stack_a);
	free_stack(stack_b);
	return (EXIT_SUCCESS);
}

void	get_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*command;

	command = get_next_line(0);
	while (command != NULL)
	{
		operate(stack_a, stack_b, command);
		free(command);
		command = get_next_line(0);
	}
}

void	operate(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp(command, "rrr\n,", 4) == 0)
		reverse_rot_both(stack_a, stack_b, 'n');
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		reverse_rotate(stack_a, 'n');
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		reverse_rotate(stack_b, 'n');
	else if (ft_strncmp(command, "sa\n", 3) == 0)
		swap(stack_a);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		swap(stack_b);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		push(stack_b, stack_a, 'n');
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		push(stack_a, stack_b, 'n');
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		rotate(stack_a, 'n');
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		rotate(stack_b, 'n');
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		rotate_both(stack_a, stack_b, 'n');
	else
	{
		write(2, "Error\n", 6);
	}
}
