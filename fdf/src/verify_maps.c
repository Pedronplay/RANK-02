/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:13:19 by pebarbos          #+#    #+#             */
/*   Updated: 2024/05/09 18:15:36 by pebarbos         ###   ########.fr       */
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
	
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
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

void	map_alloc(int height, int width, t_fdf fdf)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	fdf.mapvals.clrcodes = malloc(sizeof(float *) * fdf.map.height);
	fdf.mapvals.clrcodes = malloc(sizeof(int *) * fdf.map.height);
	while (i <= height)
	{
		while (j <= width)
		{
				fdf.mapvals.clrcodes = malloc(sizeof(float *) * fdf.map.w);
				fdf.mapvals.clrcodes = malloc(sizeof(int *) * fdf.map.w);
			j++;
		}
		i++;
	}
}
void	fill_matrix(int i, int j, char *data)
{
	(void)i; (void)j; (void)data;
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
	while (j < fdf.map.height)
	{
	//	ft_printf(" %s", line);
		splited = ft_split(line, ' ');
		while(i < fdf.map.w)
		{
			ft_printf("  %s", splited[i]);
			fill_matrix(i, j, splited[j]);  //estou aqui
			i++;
		}
		i = 1;
		free(line);
		line = get_next_line(fd);
		j++;
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
		map_alloc(fdf->map.height, fdf->map.w, *fdf);
		save_map_vals(*fdf, argv[1]);
		ft_printf("w ->%i h->%i", fdf->map.w, fdf->map.height);
		return (1);
	}
	return (0);
}
