/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:08:13 by jsala             #+#    #+#             */
/*   Updated: 2024/01/26 14:55:15 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int keysim, t_obj *obj, t_map *map)
{
	printf("Keysim value: %i, Object pointer: %p", keysim, obj);
	if (keysim == UP || keysim == W)
		map->map_content = move_up(map->map_content, map->map_size, obj);
	else if (keysim == DOWN || keysim == S)
		map->map_content = move_down(map->map_content, map->map_size, obj);
	else if (keysim == RIGHT || keysim == D)
		map->map_content = move_right(map->map_content, map->map_size, obj);
	else if (keysim == LEFT || keysim == A)
		map->map_content = move_left(map->map_content, map->map_size, obj);
	//Update map with required move... In case enemy can move, he also does a move.
	if (map->map_content == NULL)
		printf("NULL returns of map");
	else
		print_map(map->map_content);
}
// void	attack(int keysim, t_obj obj, t_map *map)

char	**move_up(char **map, t_pos size, t_obj *obj)
{
	printf("Test move up\n");
	printf("Something is wrong here, eh?\n");
    printf("The values of size, y, x are: %p, %i, %i;\n", &size, obj->pos.x, obj->pos.y);
	
	if (is_move_inbound(size, obj->pos.y - 1, obj->pos.x) == 0
		|| is_move_wall(map, obj->pos.y - 1, obj->pos.x) == 1
		|| is_player_exit(map, obj->pos.y - 1, obj->pos.x) == 1
	//	|| is_player_patrol(map, obj->pos.y - 1, obj->pos.x) == 0
	){
		printf("Something is wrong!\n");
		return (NULL);
		}
//	else if (obj_char == 'Enemy' && (map[y][x] == 'E' || map[y][x] == 'C')) // Enemies cannot path on collectibles or Exit
//		return (0);
	//Update map
//	else
//	{
	printf("I successfully pass the if statement!\n");
	map[obj->pos.y - 1][obj->pos.x] = obj->obj_char;
	map[obj->pos.y][obj->pos.x] = '0';
//	}
	return (map);
}

char	**move_down(char **map, t_pos map_size, t_obj *obj)
{
	printf("Test move down\n");
	if (is_move_inbound(map_size, obj->pos.y + 1, obj->pos.x) == 0
		|| is_move_wall(map, obj->pos.y + 1, obj->pos.x) == 1
		|| is_player_exit(map, obj->pos.y + 1, obj->pos.x) == 1
//		|| is_player_patrol(map, obj->pos.y + 1, obj->pos.x) == 0
	)
		return (0);
	printf("I successfully pass the if statement!\n");
	map[obj->pos.y + 1][obj->pos.x] = obj->obj_char;
	map[obj->pos.y][obj->pos.x] = '0';
	return (map);
}

char	**move_left(char **map, t_pos map_size, t_obj *obj)
{
	if (is_move_inbound(map_size, obj->pos.y, obj->pos.x - 1) == 0
		|| is_move_wall(map, obj->pos.y, obj->pos.x - 1) == 1
		|| is_player_exit(map, obj->pos.y, obj->pos.x - 1) == 1
//		|| is_player_patrol(map, obj->pos.y, obj->pos.x - 1) == 0
	)
		return (0);
//	else if (obj_char == 'Enemy' && (map[y][x] == 'E' || map[y][x] == 'C')) // Enemies cannot path on collectibles or Exit
//		return (0);	
	printf("I successfully pass the if statement!\n");
	map[obj->pos.y][obj->pos.x - 1] = obj->obj_char;
	map[obj->pos.y][obj->pos.x] = '0';
//	}
	return (map);
}

char	**move_right(char **map, t_pos map_size, t_obj *obj)
{
	if (is_move_inbound(map_size, obj->pos.y, obj->pos.x + 1) == 0
		|| is_move_wall(map, obj->pos.y, obj->pos.x + 1) == 1
		|| is_player_exit(map, obj->pos.y, obj->pos.x + 1) == 1
//		|| is_player_patrol(map, obj->pos.y, obj->pos.x + 1) == 0
	)
		return (0);
	//Update map
	printf("I successfully pass the if statement!\n");
	map[obj->pos.y][obj->pos.x + 1] = obj->obj_char;
	map[obj->pos.y][obj->pos.x] = '0';
	return (map);
}
