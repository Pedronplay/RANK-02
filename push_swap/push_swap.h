/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:09:40 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/30 15:39:29 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

struct	s_stack
{
	long int		val;
	struct stack	*next;
	struct stack	*prev;
};

// veryfy
int	verify_numbers(char **args);
int	verify_max(char **args);

#endif
