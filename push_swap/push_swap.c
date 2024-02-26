/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:25 by pebarbos          #+#    #+#             */
/*   Updated: 2024/02/26 16:20:13 by pedronplay       ###   ########.fr       */
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
	if (sorted(&stack_a))
		return (EXIT_SUCCESS);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	push(&stack_a, &stack_b, 'b');
	push(&stack_b, &stack_a, 'a');
	free_stack(stack_a);
}

void	printdata(t_stack *head)
{
	struct s_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("%d ", temp->val);
		temp = temp->next;
	}
	ft_printf("\n");
}
