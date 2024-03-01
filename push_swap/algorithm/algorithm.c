/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:01:55 by pedronplay        #+#    #+#             */
/*   Updated: 2024/03/01 12:11:37 by pedronplay       ###   ########.fr       */
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
	else
		big_sort(stack_a, stack_b);
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
		rotate(stack, 'a');
	else if (head->next->val == max)
		reverse_rotate(stack, 'a');
	if ((*stack)->val > (*stack)->next->val)
		swap_a(stack);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		max;

	min = get_lowest(stack_a);
	max = get_bigest(stack_a);
	while (stacksize(stack_a) > 3)
	{
		if ((*stack_a)->val == min || (*stack_a)->val == max)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, 'a');
	if ((*stack_a)->val == min && !sorted(stack_a))
	{
		swap_a(stack_a);
		rotate(stack_a, 'a');
	}
	else if (!sorted(stack_a))
		rotate(stack_a, 'a');
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	sort_until_three(stack_a, stack_b);

}

void	sort_until_three(t_stack **stack_a, t_stack **stack_b)
{
	printdata(*stack_a);
	printdata(*stack_b);
	while (stacksize(stack_a) > 3)
	{
		if (get_target_val_b(stack_b, (*stack_a)->val) == (*stack_b)->val)
			push(stack_a, stack_b, 'b');
		else 
			reverse_rotate(stack_b, 'b');
	}
	//debugging
	ft_printf("did it?\n stack b->");
	printdata(*stack_b);
	ft_printf("done it\nstack_a ->");
	printdata(*stack_a);
}