/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:08 by pedronplay        #+#    #+#             */
/*   Updated: 2024/02/26 14:56:05 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
