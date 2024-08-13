/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:56:59 by pebarbos          #+#    #+#             */
/*   Updated: 2024/06/27 21:15:42 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x_axis(float *y, int *z, t_fdf *fdf)
{
	double	save_y;

	save_y = *y;
	*y = save_y * sin(fdf->x_angle) - *z * cos(fdf->x_angle);
	*z = save_y * cos(fdf->x_angle) + *z * sin(fdf->x_angle);
}

void	rotate_y_axis(float *x, int *z, t_fdf *fdf)
{
	double	save_x;

	save_x = *x;
	*x = save_x * (cos(fdf->y_angle)) + *z * sin(fdf->y_angle);
	*z = *z * cos(fdf->y_angle) - save_x * sin(fdf->y_angle);
}

void	rotate_z_axis(float *x, float *y, t_fdf *fdf)
{
	double	save_x;
	double	save_y;

	save_x = *x;
	save_y = *y;
	*x = (save_x * cos(fdf->z_angle) - save_y * sin(fdf->z_angle));
	*y = (save_x * sin(fdf->z_angle) + save_y * cos(fdf->z_angle));
}

void	isometric_view(t_vals *p, t_fdf *fdf)
{
	rotate_x_axis(&p->y, &p->z, fdf);
	rotate_y_axis(&p->x, &p->z, fdf);
	rotate_z_axis(&p->x, &p->y, fdf);
}
