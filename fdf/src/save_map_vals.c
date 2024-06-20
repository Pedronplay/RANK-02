/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_vals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:13:12 by pebarbos          #+#    #+#             */
/*   Updated: 2024/06/19 16:40:13 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (fdf->mapvals.clrcodes)
	{
		while (i < fdf->map.height)
		{
			free(fdf->mapvals.clrcodes[i]);
			i++;
		}
		free(fdf->mapvals.clrcodes);
		fdf->mapvals.clrcodes = NULL;
	}
	i = 0;
	if (fdf->mapvals.z)
	{
		while (i < fdf->map.height)
		{
			free(fdf->mapvals.z[i]);
			i++;
		}
		free(fdf->mapvals.z);
		fdf->mapvals.z = NULL;
	}
}

void	map_alloc(int height, int width, t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->mapvals.clrcodes = malloc(sizeof(int *) * height);
	fdf->mapvals.z = malloc(sizeof(int *) * height);
	while (i < height)
	{
		fdf->mapvals.clrcodes[i] = malloc(sizeof(int) * width);
		fdf->mapvals.z[i] = malloc(sizeof(int) * width);
		i++;
	}
}

int	atoi_hexa(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] != 'x')
		i++;
	i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 16 + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			num = num * 16 + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = num * 16 + (str[i] - 'A' + 10);
		i++;
	}
	return (num);
}

void	fill_map(int i, int j, char *data, t_fdf *fdf)
{
	int		num;
	char	**colrs;

	num = 0;
	if (ft_strnstr(data, ",", 4))
	{
		colrs = ft_split(data, ',');
		fdf->mapvals.clrcodes[i][j] = atoi_hexa(colrs[1]);
		free(colrs[0]);
		free(colrs[1]);
		free(colrs);
	}
	else
		fdf->mapvals.clrcodes[i][j] = 0xffffff;
	num = ft_atoi(data);
	// alterar meter individualmente x e y
	fdf->mapvals.z[i][j] = num;
}

void	save_map_vals(t_fdf *fdf, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**splited;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (i < fdf->map.height && line != NULL)
	{
		splited = ft_split(line, ' ');
		j = 0;
		while (j < fdf->map.w)
		{
			fill_map(i, j, splited[j], fdf);
			free(splited[j]);
			j++;
		}
		free(line);
		free(splited);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
