/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:20:09 by pebarbos          #+#    #+#             */
/*   Updated: 2024/06/19 19:11:35 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free_map(fdf);
	exit (0);
}

int	handle_input(int key, void *fdf)
{
	if (key == XK_Escape)
		close_window(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (ft_handle_map(argc, argv, &fdf))
	{
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FDF Program Runing");
		mlx_key_hook(fdf.win, handle_input, &fdf);
		mlx_hook(fdf.win, DestroyNotify, NoEventMask, close_window, &fdf);
		create_img(fdf);
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
			ft_printf(" %i ", fdf.mapvals.clrcodes[y][x]);
			x++;
		}
		x = 0;
		ft_printf("\n");
		y++;
	}
}
