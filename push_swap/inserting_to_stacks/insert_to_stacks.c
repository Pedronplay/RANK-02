/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:33:30 by pebarbos          #+#    #+#             */
/*   Updated: 2024/03/06 14:56:12 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct s_stack	*create(char *nums)
{
	int				val;
	struct s_stack	*node;

	val = ft_atoi(nums);
	node = malloc(sizeof(struct s_stack));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

struct s_stack	insert_to_stacks(struct s_stack **head, char **nums)
{
	size_t	i;

	i = 1;
	*head = create(nums[0]);
	while (nums[i])
	{
		insert_to_last(*head, nums[i]);
		i++;
	}
	return (**head);
}

void	insert_to_last(struct s_stack *head, char *nums)
{
	struct s_stack	*node;

	node = create(nums);
	while (head->next != NULL)
		head = head->next;
	head->next = node;
	node->prev = head;
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
