/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:29:18 by pedronplay        #+#    #+#             */
/*   Updated: 2024/02/23 17:46:49 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*nextnode;

	temp = *stack;
	nextnode = temp->next;
	nextnode->prev = temp->prev;
	temp->prev = nextnode;
	temp->next = nextnode->next;
	nextnode->next = temp;
	*stack = nextnode;
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && stack_b)
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
	else
		return ;
}

void	swap_a(t_stack **stack_a)
{
	if (*stack_a)
		swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	if (*stack_b)
		swap(stack_b);
	ft_printf("sb\n");
}
