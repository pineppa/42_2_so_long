/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:50 by jsala             #+#    #+#             */
/*   Updated: 2024/03/27 11:18:02 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int	is_move_inbound(t_pos map_size, int x, int y)
{
	return (x > 0 && y > 0
		&& y < map_size.y && x < map_size.x); // Should not be necessary, but better check ;
}

int	is_move_wall(char **map, int x, int y)
{
	return (map[y][x] == '1');
}
*/
int	player_exit(t_map *map)
{
	if (map->n_collecs == 0)
	{
		printf("Win!\n");
		return (0);
	}
	else
		printf("Not all mushrooms were collected\n");
	return (1);
}

int	player_collect(t_map *map)
{
	printf("1 UP!\n");
	if (!(map->n_collecs > 0))
		throw_throw_error(" Collectionables should be gone by now\n");
	map->n_collecs -= 1;
	return (0);
}

int	player_patrol(void)
{
	printf("Game lost\n");
	return(0);
}
/*
int	is_move_valid(t_map *map, t_pos map_size, t_obj *obj, t_pos new_pos)
{
	return (
		move_inbound(map->map_size, new_pos.x, new_pos.y) == 0
		|| move_wall(map->map_content, new_pos.x, new_pos.y) == 1
		|| (map->map_content[new_pos.y][new_pos.x] == 'E' && !(map->n_collecs))
		//	|| player_patrol(map->map_content, new_pos.x, new_pos.y) == 0
	);
}
*/
