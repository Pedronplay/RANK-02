/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:09:40 by pebarbos          #+#    #+#             */
/*   Updated: 2024/02/26 16:18:17 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long int		val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// inserting to the stacks
struct s_stack	*create(char *nums);
struct s_stack	insert_to_stacks(struct s_stack **head, char **nums);
void			insert_to_last(struct s_stack *head, char *nums);
void			printdata(t_stack *head);

// veriyfy
int				verify_numbers(char **args);
int				verify_max(char **args);
int				verify_args(char **args);
void			free_stack(t_stack *stack);

//operations 
void			swap(t_stack **stack);
void			swap_a(t_stack **stack);
void			swap_b(t_stack **stack);
void			swap_both(t_stack **stack_a, t_stack **stack_b);
void			rotate(t_stack **stack, char leter);
void			rotate_both(t_stack **stack_a, t_stack **stack_b);
void			reverse_rotate(t_stack **stack);
void			push(t_stack **stack_a, t_stack **stack_b, char c);

//algorithm
int				get_bigest(t_stack **stack);
void			push_swap(t_stack **stack_a, t_stack **stack_b);
int				stacksize(t_stack **stack);
bool			sorted(t_stack **stack);
void			sort_three(t_stack **stack);
void			sort_five(t_stack **stack_a, t_stack **stack_b);

#endif
