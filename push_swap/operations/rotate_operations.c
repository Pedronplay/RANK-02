/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:29:41 by pedronplay        #+#    #+#             */
/*   Updated: 2024/03/06 12:04:38 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack, char leters)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	*stack = temp->next;
	temp->next->prev = NULL;
	temp->next = NULL;
	if (leters == 'a')
		ft_printf("ra\n");
	else if (leters == 'b')
		ft_printf("rb\n");
	else
		(void)leters;
}

void	reverse_rotate(t_stack **stack, char leters)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = *stack;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = (*stack);
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
	if (leters == 'a')
		ft_printf("rra\n");
	else if (leters == 'b')
		ft_printf("rrb\n");
	else
		(void)leters;
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, char l)
{
	if (*stack_a && *stack_b)
	{
		rotate(stack_a, 'n');
		rotate(stack_b, 'n');
	}
	else
		return ;
	if (l == 'y')
		ft_printf("rr\n");
}

void	reverse_rot_both(t_stack **stack_a, t_stack **stack_b, char l)
{
	if (*stack_a && *stack_b)
	{
		reverse_rotate(stack_a, 'n');
		reverse_rotate(stack_b, 'n');
	}
	else
		return ;
	if (l == 'y')
		ft_printf("rrr\n");
}

void	push(t_stack **stack_sender, t_stack **stack_receiver, char c)
{
	t_stack	*temp;

	if (*stack_sender)
	{
		temp = *stack_sender;
		*stack_sender = (*stack_sender)->next;
		if (*stack_sender)
			(*stack_sender)->prev = NULL;
		temp->next = *stack_receiver;
		if (*stack_receiver)
			(*stack_receiver)->prev = temp;
		*stack_receiver = temp;
	}
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}
