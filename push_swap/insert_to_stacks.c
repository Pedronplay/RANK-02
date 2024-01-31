/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:33:30 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/31 16:38:01 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printdata(t_stack *head)
{
	struct s_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("%d ", temp->val);
		temp = temp->next;
	}
}

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
