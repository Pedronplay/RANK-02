/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:25 by pebarbos          #+#    #+#             */
/*   Updated: 2024/03/05 17:51:47 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	else if (!process_args(argc, argv, &stack_a) || argv[1] == NULL)
	{
		write(2, "Error\n", 7);
		return (EXIT_SUCCESS);
	}
	if (sorted(&stack_a))
		return (EXIT_SUCCESS);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(stack_a) == 2)
		swap_a(stack_a);
	else if (stacksize(stack_a) == 3)
		sort_three(stack_a);
	else if (stacksize(stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
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
