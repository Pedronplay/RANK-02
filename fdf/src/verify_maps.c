/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:13:19 by pebarbos          #+#    #+#             */
/*   Updated: 2024/05/22 20:22:33 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	ft_filename(char *name, char *extension)
{
	char	*found;

	found = ft_strrchr(name, '.');
	if (!found)
		return (0);
	else
		return (ft_strncmp(found, extension, 4) == 0);
}

int	ft_count_words(char *l)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!l)
		return (0);
	while (l[i])
	{
		while (l[i] && (l[i] == ' ' || (l[i] >= 0 && l[i] <= 31)))
			i++;
		if (!l[i])
			break ;
		while (l[i] && l[i] != ' ' && l[i] != '\n')
			i++;
		words++;
	}
	return (words);
}

int	count_file_verify_lines(char *file, t_map *map)
{
	int fd;
	int	i;
	char *line;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	i = 1;
	(*map).w = ft_count_words(line);
	while (line)
	{
		if (map->w != ft_count_words(line))
		{
			i = -1;
			break;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

bool	ft_readmap(char *file, t_map *map)
{
	int n;

	n = count_file_verify_lines(file, map);
	if (n == -1)
		return (false);
	map->height = n;
	return (true); // save the data and then do that
}

void map_alloc(int height, int width, t_fdf *fdf)
{
	int i = 0;

	fdf->mapvals.clrcodes = malloc(sizeof(int *) * height);
	fdf->mapvals.z = malloc(sizeof(int *) * height);
	while (i < width)
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
	num = 1;
	while (str[i] != 'x')
		i++;
	i++;	
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			num *= str[i] - 'a' + 11;
		else if(str[i] >= 'A' && str[i] <= 'F')
			num *= str[i] - 'A' + 11;
		i++;
	}
	return(num - 1);
}

void	fill_map(int i, int j, char *data, t_fdf fdf)
{
	int num;
	char **colrs;

	num = 0;
	if (!ft_strnstr(data, "\n", 4))
	{
		if (ft_strnstr(data, ",", 4))
		{
			colrs = ft_split(data, ',');
			fdf.mapvals.clrcodes[i][j] = atoi_hexa(colrs[1]);
			ft_printf("%i", fdf.mapvals.clrcodes[i][j]);
		}
		else
			fdf.mapvals.clrcodes[i][j] = 0xffffff;
		num = ft_atoi(data);
		ft_printf("%i", num);
		fdf.mapvals.z[i][j] = num;
	}
}

void	save_map_vals(t_fdf fdf, char *file)
{
	int fd;
	int	i;
	int	j;
	char *line;
	char **splited;

	j = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (i < fdf.map.height)
	{
		splited = ft_split(line, ' ');
		while(j < fdf.map.w)
		{
			fill_map(i, j, splited[j], fdf);
			ft_printf(" ");
			j++;
		}
		ft_printf("\n");
		j = 0;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

bool	ft_handle_map(int argc, char **argv, t_fdf	*fdf)
{
	if (argc != 2)
		ft_printf("Usage : ./fdf_linux <filename>\n");
	else if (!ft_filename(argv[1], ".fdf"))
		ft_printf("Only .fdf files are allowed\n");
	else if (!ft_readmap(argv[1], &fdf->map))
		ft_printf("The file apears to not exist or be invalid\n");
	else
	{
		map_alloc(fdf->map.height, fdf->map.w, fdf);
		save_map_vals(*fdf, argv[1]);
		ft_printf("w ->%i h->%i", fdf->map.w, fdf->map.height);
		return (1);
	}
	return (0);
}
