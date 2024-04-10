/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:13:19 by pebarbos          #+#    #+#             */
/*   Updated: 2024/04/10 17:09:30 by pebarbos         ###   ########.fr       */
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
	map->height = ft_count_words(line);
	while (line)
	{
		if (map->height != ft_count_words(line))
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
	map->w = n;
	ft_printf("number%i\n", map->w);
	return (true); // save the data and then do that
}

bool	ft_handle_map(int argc, char **argv, t_map	*map)
{
	if (argc != 2)
		ft_printf("Usage : ./fdf_linux <filename>\n");
	else if (!ft_filename(argv[1], ".fdf"))
		ft_printf("Only .fdf files are allowed\n");
	else if (!ft_readmap(argv[1], map))
		ft_printf("The file apears to not exist or be invalid\n");
	else
	{	ft_printf("w ->%i h->%i", map->height, map->w);return (1);}
	return (0);
}
