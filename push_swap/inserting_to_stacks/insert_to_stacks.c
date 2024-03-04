/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:33:30 by pebarbos          #+#    #+#             */
/*   Updated: 2024/03/04 16:29:39 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	process_args(int argc, char **argv, t_stack **stack_a)
{
	char	**temp;
	size_t	i;

	temp = NULL;
	i = 0;
	if (argc == 2)
		temp = ft_split(argv[1], ' ');
	else if (argc > 2)
		argv++;
	if (!temp && verify_args(argv))
		insert_to_stacks(stack_a, argv);
	else if (temp && verify_args(temp))
		insert_to_stacks(stack_a, temp);
	if (temp)
	{
		while (temp[i])
		{
			free(temp[i]);
			i++;
		}
		free(temp);
	}
	if (!stack_a || !(*stack_a) || !(*stack_a)->val)
		return (false);
	return (true);
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
