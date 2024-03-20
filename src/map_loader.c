/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:47:27 by jsala             #+#    #+#             */
/*   Updated: 2024/03/20 14:46:39 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Collection of function to load and generate maps */

#include "so_long.h"

t_pos	get_map_size(char **map)
{
	t_pos	size;

	size.x = 0;
	size.y = 0;
	while (map[size.y])
		size.y++;
	while (map[0][size.x])
		size.x++;
	return (size);
}

int	check_ft_calloc(char *str, char *buff)
{
	if (!str || !buff)
	{
		if (str)
			free(str);
		if (buff)
			free(buff);
		return (0);
	}
	return (1);
}

char	*get_map(int fd, char *str)
{
	char	*buff;
	int		l_read;

	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
	{
		free(str);
		return (NULL);
	}
	buff[BUFFER_SIZE] = '\0';
	l_read = read(fd, buff, BUFFER_SIZE);
	while (l_read > 0)
	{
		str = ft_strjoin(str, buff);
		if (!str)
		{
			free(buff);
			return (NULL);
		}
		l_read = read(fd, buff, BUFFER_SIZE);
		buff[ft_strlen(buff)] = '\0';
	}
	free(buff);
	return (str);
}

char	**read_mapfile(int fd)
{
	char	*str;
	char	**map;

	str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (NULL);
	str = get_map(fd, str);
	if (!str)
		return (NULL);
	if (ft_strlen(str) < 5 || !check_input(str))
	{
		free(str);
		return (NULL);
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

int	load_map(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		throw_error("Error opening the file, invalid file");
		close (fd);
		return (0);
	}
	map->map_content = read_mapfile(fd);
	if (!(map->map_content))
	{
		throw_error("Error loading the map content");
		close (fd);
		return (0);
	}
	close(fd);
	map->map_size = get_map_size(map->map_content);
	if (!(map->map_size.x) || !(map->map_size.y)
		|| !is_edge_walled(map->map_content, map->map_size))
	{
		throw_error("The map does not comply with the map rules");
		return (0);
	}
	return (1);
}
