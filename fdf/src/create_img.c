/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:34:53 by pebarbos          #+#    #+#             */
/*   Updated: 2024/06/22 18:34:41 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	change_img_bg_clr(&fdf->image, 0x000000);
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.w)
		{
			if (x < fdf->map.w - 1)
				bresenam_algorithm(fdf, fdf->mapvals[y][x], fdf->mapvals[y][x + 1]);
			if (y < fdf->map.height - 1)
				bresenam_algorithm(fdf, fdf->mapvals[y][x], fdf->mapvals[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.mlx_img, 0, 0);
	return 0;
}

void	put_pixels(t_img *img, int x, int y, int clr)
{
	char	*pixel;

	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = clr;
	}
}

void	bresenam_algorithm(t_fdf *fdf, t_vals p_ini, t_vals p_end)
{
	float	x_step;
	float	y_step;
	int		max;

	p_ini.x *= 2;
	p_end.x *= 2;
	p_ini.y *= 2;
	p_end.y *= 2;
	p_ini.x += 2;
	p_end.x += 2;
	p_ini.y += 2;
	p_end.y += 2;
	x_step = p_end.x - p_ini.x;
	y_step = p_end.y - p_ini.y;
	max = max_v(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(p_ini.x - p_end.x) || (int)(p_ini.y - p_end.y))
	{
		put_pixels(&fdf->image, p_ini.x, p_ini.y, p_ini.clrcodes);
		p_ini.x += x_step;
		p_ini.y += y_step;
	}
	return;
}


/*void	create_instructions(t_fdf fdf)
{

}*/
			/*if (x < fdf.map.w)
				bresenam_algorithm(fdf.mapvals.z[x][y], fdf.mapvals.z[x + 1][y]);
			if (y < fdf.map.height)
				bresenam_algorithm(fdf.mapvals.z[x][y], fdf.mapvals.z[x][y + 1]);
			x++;*/
