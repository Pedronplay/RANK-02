/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:38:52 by pebarbos          #+#    #+#             */
/*   Updated: 2024/07/02 13:01:36 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bg_clr_chang(t_fdf *fdf)
{
	if (fdf->bg_clr == 0x000000)
		fdf->bg_clr = 0x006000;
	else if (fdf->bg_clr == 0x006000)
		fdf->bg_clr = 0x0000ff;
	else if (fdf->bg_clr == 0x0000ff)
		fdf->bg_clr = 0xff0a0a;
	else if (fdf->bg_clr == 0xff0a0a)
		fdf->bg_clr = 0x000000;
}

void	print_instructions(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 5, 15, -1,
		"Press esq or X icon to exit");
	mlx_string_put(fdf->mlx, fdf->win, 5, 30, -1,
		"Use the arrow keys to move the image");
	mlx_string_put(fdf->mlx, fdf->win, 5, 45, -1,
		"Use Z to zoom out and X to zoom in");
	mlx_string_put(fdf->mlx, fdf->win, 5, 60, -1,
		"Use W or S to rotate on X axis");
	mlx_string_put(fdf->mlx, fdf->win, 5, 75, -1,
		"Use A or D to rotate on Y axis");
	mlx_string_put(fdf->mlx, fdf->win, 5, 90, -1,
		"Use Q or E to rotate on Z axis");
	mlx_string_put(fdf->mlx, fdf->win, 5, 105, -1,
		"Use C to incerease and V to decrease the image");
	mlx_string_put(fdf->mlx, fdf->win, 5, 120, -1,
		"Press L to make it 2D");
	mlx_string_put(fdf->mlx, fdf->win, 5, 135, -1,
		"Press P to reset");
	mlx_string_put(fdf->mlx, fdf->win, 5, 150, -1,
		"Press 1 to circle trougth bg colors");
	mlx_string_put(fdf->mlx, fdf->win, 5, 165, -1,
		"Press 0 to change some other colors");
	mlx_string_put(fdf->mlx, fdf->win, 1805, 1000, -1,
		"made by pebarbos");
}

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

void	change_img_bg_clr(t_img *img, int bg_clr)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixels(img, x, y, bg_clr);
			x++;
		}
		y++;
	}
}
