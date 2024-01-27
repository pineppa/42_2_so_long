/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:50 by jsala             #+#    #+#             */
/*   Updated: 2024/01/27 18:29:04 by jsala            ###   ########.fr       */
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
		throw_error("Collectionables should be gone by now\n");
	map->n_collecs -= 1;
	return (0);
}
/*
int	player_patrol(char **map, int x, int y)
{
	if (map[y][x] == 'Patrol')
	{
		printf("Game lost");
		//play lost sound;
		//exit... return(1);
	}
	return (0);
}

int	is_move_valid(t_map *map, t_pos map_size, t_obj *obj)
{
	return (
		move_inbound(map->map_size, obj->pos.x + 1, obj->pos.y) == 0
		|| move_wall(map->map_content, obj->pos.x + 1, obj->pos.y) == 1
		|| player_exit(map->map_content, obj->pos.x + 1, obj->pos.y) == 1
		//	|| player_patrol(map->map_content, obj->pos.x + 1, obj->pos.y) == 0
	);
}
*/