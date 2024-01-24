/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:08:13 by jsala             #+#    #+#             */
/*   Updated: 2024/01/24 20:07:39 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int keysim, t_sprite spr, t_map *map)
{
	if (keysim == UP || keysim == RIGHT || keysim == LEFT
		|| keysim == DOWN || keysim == W || keysim == D 
		|| keysim == A || keysim == S)
	{
		if (keysim == UP || keysim == W)
			move_up(map->map_content, map->map_size, spr);
		else if (keysim == DOWN || keysim == S)
			move_down(map->map_content, map->map_size, spr);
		else if (keysim == RIGHT || keysim == D)
			move_right(map->map_content, map->map_size, spr);
		else if (keysim == LEFT || keysim == A)
			move_left(map->map_content, map->map_size, spr);
	}
	else
		printf("1");//play_sound();
	//Update map with required move... In case enemy can move, he also does a move.
}
// void	attack(int keysim, t_sprite spr, t_map *map)

int	move_up(char **map, t_pos map_size, t_sprite spr)
{
	if (is_move_inbound(map_size, spr.pos.y - 1, spr.pos.x) == 0
		|| is_move_wall(map, spr.pos.y - 1, spr.pos.x) == 1
		|| is_player_exit(map, spr.pos.y - 1, spr.pos.x) == 0
//		|| is_player_patrol(map, spr.pos.y - 1, spr.pos.x) == 0
	)
		return (0);
//	else if (spr_char == 'Enemy' && (map[y][x] == 'E' || map[y][x] == 'C')) // Enemies cannot path on collectibles or Exit
//		return (0);
	//Update map
	else
	{
		map[spr.pos.y - 1][spr.pos.x] = spr.spr_char;
		map[spr.pos.y][spr.pos.x] = '0';
	}
	return(1);
}

int	move_down(char **map, t_pos map_size, t_sprite spr)
{
	if (is_move_inbound(map_size, spr.pos.y + 1, spr.pos.x) == 0
		|| is_move_wall(map, spr.pos.y + 1, spr.pos.x) == 1
		|| is_player_exit(map, spr.pos.y + 1, spr.pos.x) == 0
//		|| is_player_patrol(map, spr.pos.y + 1, spr.pos.x) == 0
	)
		return (0);
	//Update map
	else
	{
		map[spr.pos.y + 1][spr.pos.x] = spr.spr_char;
		map[spr.pos.y][spr.pos.x] = '0';
	}
	return (1);
}

int	move_left(char **map, t_pos map_size, t_sprite spr)
{
	if (is_move_inbound(map_size, spr.pos.y, spr.pos.x - 1) == 0
		|| is_move_wall(map, spr.pos.y, spr.pos.x - 1) == 1
		|| is_player_exit(map, spr.pos.y, spr.pos.x - 1) == 0
//		|| is_player_patrol(map, spr.pos.y, spr.pos.x - 1) == 0
	)
		return (0);
//	else if (spr_char == 'Enemy' && (map[y][x] == 'E' || map[y][x] == 'C')) // Enemies cannot path on collectibles or Exit
//		return (0);
	//Update map
	else
	{
		map[spr.pos.y][spr.pos.x - 1] = spr.spr_char;
		map[spr.pos.y][spr.pos.x] = '0';
	}
	return(1);
}

int	move_right(char **map, t_pos map_size, t_sprite spr)
{
	if (is_move_inbound(map_size, spr.pos.y, spr.pos.x + 1) == 0
		|| is_move_wall(map, spr.pos.y, spr.pos.x + 1) == 1
		|| is_player_exit(map, spr.pos.y, spr.pos.x + 1) == 0
//		|| is_player_patrol(map, spr.pos.y, spr.pos.x + 1) == 0
	)
		return (0);
	//Update map
	else
	{
		map[spr.pos.y][spr.pos.x + 1] = spr.spr_char;
		map[spr.pos.y][spr.pos.x] = '0';
	}
	return (1);
}
