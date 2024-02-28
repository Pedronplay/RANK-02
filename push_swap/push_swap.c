/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:25 by pebarbos          #+#    #+#             */
/*   Updated: 2024/02/28 17:12:18 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1 || argv[1][0] == '\0')
		return (1);
	else if (!process_args(argc, argv, &stack_a))
	{
		ft_printf("Error\n");
		return (EXIT_SUCCESS);
	}
	if (sorted(&stack_a))
		return (EXIT_SUCCESS);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	ft_printf("\n\n Target position-> \"5\" %d\n",get_position(&stack_a, 5));
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
