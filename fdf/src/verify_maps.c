/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:13:19 by pebarbos          #+#    #+#             */
/*   Updated: 2024/04/03 13:45:30 by pebarbos         ###   ########.fr       */
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

int	count_file_verify_lines(char *file)
{
	int fd;
	int	i;
	char *line;
	char *temp;
	char **splited;
	size_t size;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		temp = line;
		line = ft_strtrim(line, "\n");
		free(temp);
 		splited = ft_split(line, ' ');
		free(line);
		if (splited == NULL)
			continue ;
		if (*splited == NULL)
		{
			free(splited);
			continue ;
		}
		size = 0;
		while (splited[size])
		{
			printf("->%s", splited[size]);
			size++;
		}
		printf("\n");
		i++;
		line = get_next_line(fd);
	}
	ft_printf("lines->%i\n", i);
	ft_printf("elements->%i", size);
	return (i);
}

bool	ft_readmap(char *file, t_map map)
{
	(void)map;
	int n;

	n = count_file_verify_lines(file);
	if (n == -1)
		return (false);
	return (true);
}

bool	ft_handle_map(int argc, char **argv, t_map	map)
{
	if (argc != 2)
		ft_printf("Usage : ./fdf_linux <filename>\n");
	else if (!ft_filename(argv[1], ".fdf"))
		ft_printf("Only .fdf files are allowed\n");
	else if (!ft_readmap(argv[1], map))
		ft_printf("The file apears to not exist or be invalid\n");
	else
		return (1);
	return (0);
}