/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:52:38 by pedronplay        #+#    #+#             */
/*   Updated: 2024/03/06 14:54:33 by pedronplay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	get_instructions(t_stack **a, t_stack **b);
void	operate(t_stack **stack_a, t_stack **stack_b, char *command);

#endif
