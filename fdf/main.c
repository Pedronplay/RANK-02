/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeunome <omeunome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:20:09 by pebarbos          #+#    #+#             */
/*   Updated: 2024/07/06 12:49:23 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_printf("\n--> %%");
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

/*//############# debugging
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
}*/
