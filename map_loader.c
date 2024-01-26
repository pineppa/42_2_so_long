/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:47:27 by jsala             #+#    #+#             */
/*   Updated: 2024/01/25 19:49:54 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Collection of function to load and generate maps */

#include "so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

t_pos	get_map_size(char **map)
{
	t_pos	size;

	size.x = 0;
	size.y = 0;
	while(map[size.y])
		size.y++; // Does this work correctly?
	while(map[0][size.x])
		size.x++;
	return (size);
}

char	**read_mapfile(int fd)
{
	char	*buff;
	char	*str;
	char	**map;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	str = malloc(sizeof(char) * 1); // Check if it makes sense
	if (!str || !buff)
	{
		free(buff);
		return (NULL);
	}
	str[0] = '\0';
	buff[BUFFER_SIZE] = '\0';
	while (read(fd, buff, BUFFER_SIZE))
		str = ft_strjoin(str, buff);
	free(buff);
	if (!check_input(str))
	{
		free(str);
		write(2, "The input map is not valid", 26);
		return (NULL);
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

int	load_map(char *file, t_map *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		throw_error("Error opening the file, invalid fd");
		return (0);
	}
	map->map_content = read_mapfile(fd); // returns a malloc'd array
	if (!(map->map_content))
	{
		throw_error("Error loading map content");
		return (0);
	}
	map->map_size = get_map_size(map->map_content);
	close(fd);
	if (!(map->map_size.x) || !(map->map_size.y) 
		|| !is_edge_walled(map->map_content, map->map_size))
	{
		throw_error("Map file Error");
		return (0);
	}
	return (1);
}
