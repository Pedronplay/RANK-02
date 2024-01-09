/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:52:25 by pebarbos          #+#    #+#             */
/*   Updated: 2023/11/08 15:14:57 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_print_base(long int s, int n, char p, size_t cont);
int	ft_print_ptr(unsigned long long s, int n, char p, size_t cont);
int	ft_print_char(unsigned char s);
int	ft_print_str(char *s);

#endif
