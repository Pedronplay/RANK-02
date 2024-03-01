/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:49:21 by pedronplay        #+#    #+#             */
/*   Updated: 2024/03/01 12:13:18 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_target_val_b(t_stack **stack_b, int current)
{
	t_stack	*head;
	int		target;

	target = INT_MIN;
	head = *stack_b;
	while (head)
	{
		if (head->val < current && head->val > target)
			target = head->val;
		head = head->next;
	}
	if (target == INT_MIN)
		target = get_bigest(stack_b);
	return (target);
}

int	get_target_val_a(t_stack **stack_a, int current)
{
	t_stack	*head;
	int		target;

	target = INT_MAX;
	head = *stack_a;
	while (head)
	{
		if (head->val > current && head->val < target)
			target = head->val;
		head = head->next;
	}
	if (target == INT_MAX)
		target = get_lowest(stack_a);
	return (target);
}



