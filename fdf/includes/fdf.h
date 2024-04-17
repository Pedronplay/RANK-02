/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:32:15 by pebarbos          #+#    #+#             */
/*   Updated: 2024/04/17 19:42:04 by pebarbos         ###   ########.fr       */
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
	int	clrcodes;
}	t_vals;

typedef struct s_map
{
	int	w; // thinking how im  going to store this data
	int	height; // need x,y,z and collor
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_map	mapvals;
}	t_fdf;

# define ESC_KEY 65307

//			verify maps       //
bool	ft_handle_map(int argc, char **argv, t_map *map);

#endif