/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:01:55 by pedronplay        #+#    #+#             */
/*   Updated: 2024/02/26 16:12:48 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(stack_a) == 2)
	swap_a(stack_a);
	else if (stacksize(stack_a) == 3)
		sort_three(stack_a);
	else if (stacksize(stack_a) <= 5)
		sort_five(stack_a, stack_b);
	ft_printf("stack size ->%d\n", stacksize(stack_a));
	// Debuging stuff
	printdata(*stack_a);
	(void)stack_b;
}

void	sort_three(t_stack **stack)
{
	t_stack	*head;
	int		max;

	if (sorted(stack))
		return ;
	max = get_bigest(stack);
	head = *stack;
	if (head->val == max)
	{
		rotate(stack, 'a');
	}
	else if (head->next->val == max)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	if ((*stack)->val > (*stack)->next->val)
		swap_a(stack);
}

void			sort_five(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	(void)stack_b;
}