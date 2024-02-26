/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:29:41 by pedronplay        #+#    #+#             */
/*   Updated: 2024/02/26 17:35:35 by pedronplay       ###   ########.fr       */
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
	t_stack	*temp;
	t_stack	*last;

	temp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
		if (leters == 'a')
		ft_printf("rra\n");
	else if (leters == 'b')
		ft_printf("rrb\n");
	else
		(void)leters;
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		rotate(stack_a, 'n');
		rotate(stack_b, 'n');
		ft_printf("rr\n");
	}
	else
		return ;
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		reverse_rotate(stack_a, 'n');
		reverse_rotate(stack_b, 'n');
		ft_printf("rrr\n");
	}
	else
		return ;
}
