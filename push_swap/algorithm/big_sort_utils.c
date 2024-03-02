/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:49:21 by pedronplay        #+#    #+#             */
/*   Updated: 2024/03/02 17:47:04 by pedronplay       ###   ########.fr       */
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

int	get_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	int		moves;
	int		cost;
	t_stack	*temp;

	temp = *stack_a;
	cheapest = temp->val;
	cost = INT_MAX;
	while (temp)
	{
		moves = get_total(stack_a, stack_b, temp->val);
		if (cost > moves)
		{
			cheapest = temp->val;
			cost = moves;
		}
		if (moves <= 1)
			return (cheapest);
		temp = temp->next;
	}
	return (cheapest);
}

int	get_total(t_stack **stack_a, t_stack **stack_b, int val)
{
	int	cost_a;
	int	cost_b;
	int	total;

	cost_a = targetdist(stack_a, val);
	cost_b = targetdist(stack_b, get_target_val_b(stack_b, val));
	if (cost_a < 0)
		cost_a *= -1;
	if (cost_b < 0)
		cost_b *= -1;
	total = cost_a + cost_b;
	return (total);
}

int	targetdist(t_stack **stack, int val)
{
	int	distance;
	int	midle;

	distance = 0;
	midle = stacksize(stack) / 2;
	if (get_position(stack, val) <= midle)
		distance = get_position(stack, val);
	else
		distance = get_position(stack, val) - stacksize(stack);
	return(distance);
}