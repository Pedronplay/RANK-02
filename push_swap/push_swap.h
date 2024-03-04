/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:09:40 by pebarbos          #+#    #+#             */
/*   Updated: 2024/03/04 16:34:15 by pedronplay       ###   ########.fr       */
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

// starting
void			push_swap(t_stack **stack_a, t_stack **stack_b);

// inserting to the stacks
bool			process_args(int argc, char **argv, t_stack **stack_a);
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
void			reverse_rotate(t_stack **stack, char c);
void			reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void			push(t_stack **stack_a, t_stack **stack_b, char c);

//algorithm
void			sort_three(t_stack **stack);
void			sort_five(t_stack **stack_a, t_stack **stack_b);
void			big_sort(t_stack **stack_a, t_stack **stack_b);
void			sort_until_three(t_stack **stack_a, t_stack **stack_b);
void			back_to_a(t_stack **stack_a, t_stack **stack_b);

//algorithm utils
int				get_bigest(t_stack **stack);
int				get_lowest(t_stack**stack);
int				stacksize(t_stack **stack);
bool			sorted(t_stack **stack);
int				get_position(t_stack **stack, int target);

//big sort utils
int				get_tar_val_b(t_stack **stack_b, int current);
int				get_tar_val_a(t_stack **stack_b, int current);
int				get_cheapest(t_stack **stack_a, t_stack **stack_b);
int				get_total(t_stack **stack_a, t_stack **stack_b, int cal);
int				targetdist(t_stack	**stack, int val);

#endif
