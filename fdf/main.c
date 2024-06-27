/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:20:09 by pebarbos          #+#    #+#             */
/*   Updated: 2024/06/27 19:42:53 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	close_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image.mlx_img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free_map(fdf);
	exit (0);
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
	return (0);
}

void	printa_mapa(t_fdf fdf);

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	
	if (ft_handle_map(argc, argv, &fdf))
	{
		set_moves(&fdf);
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FDF Program Runing");
		fdf.image.mlx_img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
		fdf.image.addr = mlx_get_data_addr(fdf.image.mlx_img, &fdf.image.bpp,
			&fdf.image.line_len, &fdf.image.endian);
		mlx_hook(fdf.win, KeyPress, KeyPressMask, handle_input, &fdf);
		mlx_loop_hook(fdf.mlx, &draw, &fdf);
		mlx_hook(fdf.win, DestroyNotify, NoEventMask, close_window, &fdf);
		mlx_do_key_autorepeaton(fdf.mlx);
		mlx_loop(fdf.mlx);
	}
}

//############# debugging
void	printa_mapa(t_fdf fdf)
{
	int x = 0;
	int y = 0;
	while(y < fdf.map.height)
	{
		while (x < fdf.map.w)
		{
			ft_printf(" %i ", fdf.mapvals[y][x].z);
			x++;
		}
		x = 0;
		ft_printf("\n");
		y++;
	}
}
