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

void	rotate_x_axis(float *y, int *z)
{
	double	save_y;

	save_y = *y;
	*y = save_y * (sqrt(3) / 3) - *z * (sqrt(6)/ 3);
	*z = save_y * (sqrt(6)/ 3) + *z * (sqrt(3) / 3);
}

void	rotate_y_axis(float *x, int *z)
{
	double	save_x;

	save_x = *x;
	*x = save_x * (cos(0.141592)) + *z * sin(0.141592);
	*z = *z * cos(0.141592) - save_x * sin(0.141592);
}

void	rotate_z_axis(float *x, float *y)
{
	double	save_x;
	double	save_y;

	save_x = *x;
	save_y = *y;
	*x = (save_x * cos(0.243534) - save_y * sin(0.243534));
	*y = (save_x * sin(0.243534) + save_y * cos(0.243534));
}