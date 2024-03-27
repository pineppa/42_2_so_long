/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:35:35 by jsala             #+#    #+#             */
/*   Updated: 2024/03/27 10:46:44 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	ft_update_pos(t_pos pos, int x, int y)
{
	pos.x = x;
	pos.y = y;
	return (pos);
}

char	**copy_map(t_pos size, char **map)
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
		{
			free_matrix(temp_map);
			return (NULL);
		}
		temp_map[i][size.x] = '\0';
		while (++j < size.x)
			temp_map[i][j] = map[i][j];
	}
	return (temp_map);
}

int	is_valid_path(char **temp_map, t_pos pos, int *n_collecs, int *n_exits)
{
	t_pos	temp_pos1;
	t_pos	temp_pos2;

	if (temp_map[pos.y][pos.x] == '1')
		return (0);
	else
	{
		if (temp_map[pos.y][pos.x] == 'E')
			*n_exits -= 1;
		else if (temp_map[pos.y][pos.x] == 'C')
			*n_collecs -= 1;
		temp_map[pos.y][pos.x] = '1';
	}
	temp_pos1 = ft_update_pos(pos, pos.x - 1, pos.y);
	temp_pos2 = ft_update_pos(pos, pos.x + 1, pos.y);
	if ((*n_exits == 0 && *n_collecs == 0)
		|| is_valid_path(temp_map, temp_pos1, n_collecs, n_exits)
		|| is_valid_path(temp_map, temp_pos2, n_collecs, n_exits))
		return (1);
	temp_pos1 = ft_update_pos(pos, pos.x, pos.y - 1);
	temp_pos2 = ft_update_pos(pos, pos.x, pos.y + 1);
	if (is_valid_path(temp_map, temp_pos1, n_collecs, n_exits)
		|| is_valid_path(temp_map, temp_pos2, n_collecs, n_exits))
		return (1);
	return (0);
}

int	check_valid_path(t_map *map, t_pos p1_pos)
{
	char	**temp_map;
	int		n_coll;
	int		n_exits;

	temp_map = copy_map(map->map_size, map->map_content);
	if (!temp_map)
		return (0);
	n_coll = map->n_collecs;
	n_exits = map->n_exits;
	if (!is_valid_path(temp_map, p1_pos, &n_coll, &n_exits))
	{
		free_matrix(temp_map);
		return (0);
	}
	free_matrix(temp_map);
	return (1);
}
