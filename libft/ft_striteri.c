/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:05:00 by pebarbos          #+#    #+#             */
/*   Updated: 2023/10/24 11:37:30 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void printCharAtIndex(unsigned int index, char *c) {
    printf("Character at index %u is: %c\n", index, *c);
}

int main(void) {
    char str[] = "Hello, World!";
    
    printf("Original string: %s\n", str);
    
    ft_striteri(str, printCharAtIndex);
    
    return 0;
}
 */
