/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:32:15 by pebarbos          #+#    #+#             */
/*   Updated: 2024/07/02 13:00:07 by pebarbos         ###   ########.fr       */
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
	float	x;
	float	y;
	int		z;
	int		clrcodes;
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
	int		moves_x;
	int		moves_y;
	int		moves_zoom;
	int		z_range;
	int		bg_clr;
	float	x_angle;
	float	y_angle;
	float	z_angle;
	bool	ln_clr;
	t_map	map;
	t_img	image;
	t_vals	**mapvals;
}	t_fdf;

# define WIDTH 1920
# define HEIGHT 1080

//			verify maps       //
bool	ft_handle_map(int argc, char **argv, t_fdf *map);
void	save_map_vals(t_fdf *fdf, char *file);
void	map_alloc(int height, int width, t_fdf *fdf);
void	free_map(t_fdf *fdf);

//			create_maps		//
void	set_moves(t_fdf *fdf);
void	bresenam_algorithm(t_fdf *fdf, t_vals ini, t_vals p_end);
int		draw(t_fdf *fdf);
void	put_pixels(t_img *img, int x, int y, int clr);

//			draw_utils		//
void	print_instructions(t_fdf *fdf);
void	change_img_bg_clr(t_img *img, int bg_clr);
int		mod(int num);
int		max_v(int n1, int n2);
void	bg_clr_chang(t_fdf *fdf);

//			rotations		//
void	isometric_view(t_vals *p, t_fdf *fdf);
void	rotate_x_axis(float *y, int *z, t_fdf *fdf);
void	rotate_y_axis(float *x, int *z, t_fdf *fdf);
void	rotate_z_axis(float *x, float *y, t_fdf *fdf);

//			signals			//
int		close_window(t_fdf *fdf);
int		handle_input(int key, t_fdf	*fdf);
int		more_signals(int key, t_fdf *fdf);

#endif
