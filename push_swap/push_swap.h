/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:09:40 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/31 16:53:53 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long int		val;
	struct s_stack	*next;
	struct s_stack	*prev;
}t_stack;

// inserting to the stacks
struct s_stack	*create(char *nums);
struct s_stack	insert_to_stacks(struct s_stack **head, char **nums);
void			insert_to_last(struct s_stack *head, char *nums);
void			printdata(t_stack *head);

// veriyfy
int				verify_numbers(char **args);
int				verify_max(char **args);
int				verify_args(char **args);

#endif
