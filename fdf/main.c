/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:20:09 by pebarbos          #+#    #+#             */
/*   Updated: 2024/03/13 15:51:51 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./minilibx-linux/mlx.h"

int	handle_input(int key, void *param)
{
	(void)key;
	(void)param;
	return (0);
}
int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Window");
	mlx_key_hook(win, handle_input, NULL);
	mlx_loop(mlx);
	if (!mlx)
		return (1);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
