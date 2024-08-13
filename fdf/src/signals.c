/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:51:04 by pebarbos          #+#    #+#             */
/*   Updated: 2024/07/02 13:01:15 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image.mlx_img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free_map(fdf);
	exit (0);
}

int	more_signals(int key, t_fdf *fdf)
{
	if (key == XK_a)
		fdf->y_angle -= 0.1;
	if (key == XK_w)
		fdf->x_angle += 0.1;
	if (key == XK_s)
		fdf->x_angle -= 0.1;
	if (key == XK_q)
		fdf->z_angle += 0.1;
	if (key == XK_e)
		fdf->z_angle -= 0.1;
	if (key == XK_l)
	{
		fdf->x_angle = 3.1415926 / 2;
		fdf->y_angle = 0;
		fdf->z_angle = 0;
	}
	if (key == XK_p)
		set_moves(fdf);
	if (key == XK_1)
		bg_clr_chang(fdf);
	if (key == XK_0)
		fdf->ln_clr = true;
	return (1);
}

int	handle_input(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		close_window(fdf);
	if (key == XK_Left)
		fdf->moves_x -= 20;
	if (key == XK_Right)
		fdf->moves_x += 20;
	if (key == XK_Up)
		fdf->moves_y -= 20;
	if (key == XK_Down)
		fdf->moves_y += 20;
	if (key == XK_x && (fdf->moves_zoom <= 100 && fdf->map.height < 80))
		fdf->moves_zoom += 5;
	if (key == XK_x && (fdf->moves_zoom <= 20 && fdf->map.height > 80))
		fdf->moves_zoom += 1;
	if (key == XK_z && fdf->moves_zoom >= 3)
		fdf->moves_zoom -= 1;
	if (key == XK_c)
		fdf->z_range -= 1;
	if (key == XK_v)
		fdf->z_range += 1;
	if (key == XK_d)
		fdf->y_angle += 0.1;
	more_signals(key, fdf);
	return (1);
}
