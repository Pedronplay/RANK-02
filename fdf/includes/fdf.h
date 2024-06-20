/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:32:15 by pebarbos          #+#    #+#             */
/*   Updated: 2024/06/19 21:04:24 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>

//			structs				//
typedef struct s_vals
{
	int	**z;
	int	**clrcodes;
}	t_vals;

typedef struct s_map
{
	int	w; 
	int	height;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr; //adress
	int		bpp; //bit per pixel
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_vals	mapvals;
	t_img	image;
}	t_fdf;

# define WIDTH 1920
# define HEIGHT 1080

//			verify maps       //
bool	ft_handle_map(int argc, char **argv, t_fdf *map);
void	save_map_vals(t_fdf *fdf, char *file);
void	map_alloc(int height, int width, t_fdf *fdf);
void	free_map(t_fdf *fdf);

//			create_maps		//
void	create_img(t_fdf fdf);
void	bresenam_algorithm(t_fdf fdf);

#endif