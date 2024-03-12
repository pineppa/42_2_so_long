/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:35:35 by jsala             #+#    #+#             */
/*   Updated: 2024/03/12 09:24:40 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_map(t_pos size, char **map)
{
	char	**temp_map;
	int		i;
	int		j;

	temp_map = ft_calloc(sizeof(char *), (size.y + 1));
	if (!temp_map)
		return (NULL);
	temp_map[size.y] = NULL;
	i = -1;
	while (++i < size.y)
	{
		j = -1;
		temp_map[i] = ft_calloc(sizeof(char), (size.x + 1));
		if (!temp_map)
			return (NULL);
		temp_map[i][size.x] = '\0';
		while (++j < size.x)
			temp_map[i][j] = map[i][j];
	}
	return (temp_map);
}

int is_valid_path(char **temp_map, int x, int y, int n_collecs)
{
	if (temp_map[y][x] == '1')
		return (0);
	else if (temp_map[y][x] == 'P' || temp_map[y][x] == '0')
		temp_map[y][x] = '1';
	else if (temp_map[y][x] == 'E')
	{
		if (n_collecs == 0)
			return (1);
		return (0);
	}
	else if (temp_map[y][x] == 'C') // There is something wrong with this, probably finds exit before all collectibles
	{
		n_collecs--;
		temp_map[y][x] = '1';
	}
	return (is_valid_path(temp_map, x - 1, y, n_collecs)
		|| is_valid_path(temp_map, x + 1, y, n_collecs)
		|| is_valid_path(temp_map, x, y - 1, n_collecs)
		|| is_valid_path(temp_map, x, y + 1, n_collecs));
}

int check_valid_path(t_map *map)
{
	char	**temp_map;

	temp_map = copy_map(map->map_size, map->map_content);
	if (!temp_map)
		return (0);
	printf("CIAIOSDONSDOAsDas");
	if (!is_valid_path(temp_map, map->p1->pos.x, map->p1->pos.y,
		map->n_collecs))
	{
		printf("path:\npos.x: %i, pos.y: %i, collecs: %i", map->p1->pos.x, map->p1->pos.y, map->n_collecs);
		throw_error("What is wrong with meeeeee?\n");
		free_matrix(temp_map);
		return (0);
	}
	printf("CIAIOSDONSDOAsDas");
	free_matrix(temp_map);
	return (1);
}
