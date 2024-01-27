/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:08:13 by jsala             #+#    #+#             */
/*   Updated: 2024/01/27 12:50:27 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keysim, t_obj *obj, t_map *map)
{
	int	res;

	res = 0;
	printf("Keysim value: %i, Object pointer: %p", keysim, obj);
	if (keysim == UP || keysim == W)
		res = move_up(&(map->map_content), map->map_size, obj);
	else if (keysim == DOWN || keysim == S)
		res = move_down(&(map->map_content), map->map_size, obj);
	else if (keysim == RIGHT || keysim == D)
		res = move_right(&(map->map_content), map->map_size, obj);
	else if (keysim == LEFT || keysim == A)
		res = move_left(&(map->map_content), map->map_size, obj);
	//Update map with required move... In case enemy can move, he also does a move.
	return (res);
}
// void	attack(int keysim, t_obj obj, t_map *map)

int	move_up(char ***map, t_pos size, t_obj *obj)
{
	if (is_move_inbound(size, obj->pos.x, obj->pos.y - 1) == 0
		|| is_move_wall(*map, obj->pos.x, obj->pos.y - 1) == 1
		|| is_player_exit(*map, obj->pos.x, obj->pos.y - 1) == 1
		//	|| is_player_patrol(*map, obj->pos.x, obj->pos.y - 1) == 0
	)
	{
		printf("Something is wrong!\n");
		return (0);
	}
//	else if (obj_char == 'Enemy' && (map[y][x] == 'E' || map[y][x] == 'C')) // Enemies cannot path on collectibles or Exit
//		return (0);
	(*map)[obj->pos.y - 1][obj->pos.x] = obj->obj_char;
	(*map)[obj->pos.y][obj->pos.x] = '0';
	return (1);
}

int	move_down(char ***map, t_pos map_size, t_obj *obj)
{
	if (is_move_inbound(map_size, obj->pos.x, obj->pos.y + 1) == 0
		|| is_move_wall(*map, obj->pos.x, obj->pos.y + 1) == 1
		|| is_player_exit(*map, obj->pos.x, obj->pos.y + 1) == 1
//		|| is_player_patrol(*map, obj->pos.x, obj->pos.y + 1) == 0
	)
		return (0);
	(*map)[obj->pos.y + 1][obj->pos.x] = obj->obj_char;
	(*map)[obj->pos.y][obj->pos.x] = '0';
	return (1);
}

int	move_left(char ***map, t_pos map_size, t_obj *obj)
{
	if (is_move_inbound(map_size, obj->pos.x - 1, obj->pos.y) == 0
		|| is_move_wall(*map, obj->pos.x - 1, obj->pos.y) == 1
		|| is_player_exit(*map, obj->pos.x - 1, obj->pos.y) == 1
//		|| is_player_patrol(*map, obj->pos.x - 1, obj->pos.y) == 0
	)
		return (0);
//	else if (obj_char == 'Enemy' && (map[y][x] == 'E' || map[y][x] == 'C')) // Enemies cannot path on collectibles or Exit
//		return (0);	
	(*map)[obj->pos.y][obj->pos.x - 1] = obj->obj_char;
	(*map)[obj->pos.y][obj->pos.x] = '0';
//	}
	return (1);
}

int	move_right(char ***map, t_pos map_size, t_obj *obj)
{
	if (is_move_inbound(map_size, obj->pos.x + 1, obj->pos.y) == 0
		|| is_move_wall(*map, obj->pos.x + 1, obj->pos.y) == 1
		|| is_player_exit(*map, obj->pos.x + 1, obj->pos.y) == 1
		//	|| is_player_patrol(*map, obj->pos.x + 1, obj->pos.y) == 0
	)
		return (0);
	(*map)[obj->pos.y][obj->pos.x + 1] = obj->obj_char;
	(*map)[obj->pos.y][obj->pos.x] = '0';
	return (1);
}
