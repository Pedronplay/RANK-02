/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:34:53 by pebarbos          #+#    #+#             */
/*   Updated: 2024/07/02 13:03:45 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	change_img_bg_clr(&fdf->image, fdf->bg_clr);
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.w)
		{
			if (x < fdf->map.w - 1)
				bresenam_algorithm(fdf,
					fdf->mapvals[y][x], fdf->mapvals[y][x + 1]);
			if (y < fdf->map.height - 1)
				bresenam_algorithm(fdf,
					fdf->mapvals[y][x], fdf->mapvals[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.mlx_img, 0, 0);
	print_instructions(fdf);
	return (0);
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

void	set_moves(t_fdf *fdf)
{
	fdf->moves_x = 700;
	fdf->moves_y = 350;
	fdf->moves_zoom = 40;
	fdf->z_range = 5;
	fdf->x_angle = 0.837911828;
	fdf->y_angle = -0.141592;
	fdf->z_angle = 0.243534;
	fdf->bg_clr = 0x000000;
	fdf->ln_clr = false;
	if (fdf->map.height > 18)
	{
		fdf->moves_x = 800;
		fdf->moves_y = 200;
		fdf->moves_zoom = 20;
	}
	if (fdf->map.height > 80)
	{
		fdf->moves_x = 800;
		fdf->moves_y = 200;
		fdf->moves_zoom = 2;
	}
}

void	set_initial_pos(t_fdf *fdf, t_vals *p_ini, t_vals *p_end)
{
	p_ini->x *= fdf->moves_zoom;
	p_end->x *= fdf->moves_zoom;
	p_ini->y *= fdf->moves_zoom;
	p_end->y *= fdf->moves_zoom;
	p_ini->z *= fdf->moves_zoom;
	p_end->z *= fdf->moves_zoom;
	p_ini->z *= fdf->z_range * 0.05;
	p_end->z *= fdf->z_range * 0.05;
	isometric_view(p_ini, fdf);
	isometric_view(p_end, fdf);
	p_ini->x += fdf->moves_x;
	p_end->x += fdf->moves_x;
	p_ini->y += fdf->moves_y;
	p_end->y += fdf->moves_y;
}

void	bresenam_algorithm(t_fdf *fdf, t_vals p_ini, t_vals p_end)
{
	float	x_step;
	float	y_step;
	int		max;

	if ((p_ini.z != 0 || p_end.z != 0)
		&& p_ini.clrcodes == 0xffffff && fdf->ln_clr)
		p_ini.clrcodes = 0xff00ff;
	set_initial_pos(fdf, &p_ini, &p_end);
	x_step = p_end.x - p_ini.x;
	y_step = p_end.y - p_ini.y;
	max = max_v(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p_ini.x - p_end.x) || (int)(p_ini.y - p_end.y))
	{
		put_pixels(&fdf->image, p_ini.x, p_ini.y, p_ini.clrcodes);
		p_ini.x += x_step;
		p_ini.y += y_step;
	}
	return ;
}
