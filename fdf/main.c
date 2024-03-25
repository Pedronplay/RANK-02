/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:20:09 by pebarbos          #+#    #+#             */
/*   Updated: 2024/03/25 16:49:10 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	close_window(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	exit (0);
}

int	handle_input(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == ESC_KEY)
		close_window(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_map	map;

	(void)fdf;
	if (ft_handle_map(argc, argv, map))
	{
		//fdf.mlx = mlx_init();
//		fdf.win = mlx_new_window(fdf.mlx, 800, 600, "FDF Program Runing");
//		mlx_key_hook(fdf.win, handle_input, &fdf);
//		mlx_loop(fdf.mlx);
		ft_printf("yay\n");
	}
}
