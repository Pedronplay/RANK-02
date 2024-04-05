/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:10:04 by pebarbos          #+#    #+#             */
/*   Updated: 2024/04/05 15:56:56 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*tmps;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmps = ft_read_file(fd, tmps);
	if (!tmps)
	{
		return (NULL);
	}
	line = ft_get_line(tmps);
	tmps = ft_trim(tmps);
	return (line);
}

char	*ft_get_line(char *tmps)
{
	char	*linha;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!tmps[i])
		return (NULL);
	while (tmps[i] != '\n' && tmps[i] != '\0')
		i++;
	linha = ft_calloc(sizeof(char *), i + 1);
	while (j <= i)
	{
		linha[j] = tmps[j];
		j++;
	}
	linha[j] = '\0';
	return (linha);
}

char	*ft_trim(char *tmps)
{
	size_t	sub;
	size_t	i;
	char	*trimed;

	sub = 0;
	i = 0;
	while (tmps[sub] != '\0' && tmps[sub] != '\n')
		sub++;
	if (!tmps[i])
		return (free(tmps), NULL);
	trimed = ft_calloc(sizeof(char), ft_strlen(tmps) - sub + 1);
	if (tmps[sub] == '\n')
		sub++;
	while (tmps[sub] != '\0')
	{
		trimed[i] = tmps[sub];
		sub++;
		i++;
	}
	trimed[i] = '\0';
	free(tmps);
	return (trimed);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*str;
	size_t	j;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(sizeof(char), (j + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_read_file(int fd, char *tmps)
{
	char	*buffer_data;
	int		i;

	i = 1;
	if (!tmps)
		tmps = ft_calloc(1, 1);
	buffer_data = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer_data)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, buffer_data, BUFFER_SIZE);
		if (i == -1)
			break ;
		buffer_data[i] = '\0';
		tmps = ft_strjoin_get(tmps, buffer_data);
		if (ft_strchr(buffer_data, '\n'))
			break ;
	}
	free(buffer_data);
	if (!*tmps || i == -1)
		return (free(tmps), NULL);
	return (tmps);
}

/*
int	main(void)
{
	int	fd;
	char	*cunt;
 	int i = 0;

	fd = open("get_next_line.c", O_RDONLY);
	while ((cunt = get_next_line(fd)))
	{

		printf("%s", cunt);
		free(cunt);
	}
}
 */
