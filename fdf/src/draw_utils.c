/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:38:52 by pebarbos          #+#    #+#             */
/*   Updated: 2024/06/22 18:30:22 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mod(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int	max_v(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

void	change_img_bg_clr(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			put_pixels(img, x, y, color);
			x++;
		}
		y++;
	}

}
