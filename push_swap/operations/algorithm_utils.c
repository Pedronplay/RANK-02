/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:15:55 by pedronplay        #+#    #+#             */
/*   Updated: 2024/02/26 15:53:31 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stacksize(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = *stack;
	if (temp == NULL)
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

bool	sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head->next != NULL)
	{
		if (head->val > head->next->val)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_bigest(t_stack **stack)
{
	int		max;
	t_stack	*temp;

	max = INT_MIN;
	temp = *stack;
	while (temp)
	{
		if (temp->val > max)
			max = temp->val;
		temp = temp->next;
	}
	return (max);
}
