/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:08:13 by jsala             #+#    #+#             */
/*   Updated: 2024/01/23 22:08:46 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// The input values are the new ones. Returns 1 is is valid, 0 if it is not;
int is_valid_move(t_map *map, char sprite_char, int x, int y)
{
	if (x < 1 || y < 1 
		|| x > (map->map_size->x - 1) || y > (map->map_size->y - 1)) // Should not be necessary, but better check 
		return (0);
	if (map[y][x] == '1') // If it is a wall return
		return (0);
	else if (sprite_char == 'Enemy' && (map[y][x] == 'E' || map[y][x] == 'C')) // Enemies cannot path on collectibles or Exit
		return (0);
	return (1);	
}

void	move(int keysim, t_sprite spr, t_map *map)
{
	if ((keysim == XK_Up || keysim == XK_W)
		&& !is_valid_move(map, spr.spr_char, spr.pos.y - 1, spr.pos.x))
		map[spr.pos.y - 1][spr.pos.x] = spr.spr_char;
	else if ((keysim == XK_Down || keysim == XK_S)
		&& !is_valid_move(map, spr.spr_char, spr.pos.y + 1, spr.pos.x))
		map[spr.pos.y + 1][spr.pos.x] = spr.spr_char;
	else if ((keysim == XK_Right || keysim == XK_D)
		&& !is_valid_move(map, spr.spr_char, spr.pos.y, spr.pos.x + 1))
		map[spr.pos.y][spr.pos.x + 1] = spr.spr_char;
	else if ((keysim == XK_Left || keysim == XK_A)
		&& !is_valid_move(map, spr.spr_char, spr.pos.y, spr.pos.x - 1))
		map[spr.pos.y][spr.pos.x - 1] = spr.spr_char;
	map[spr.pos.y][spr.pos.x] = '0';
	//Update map with required move... In case enemy can move, he also does a move.
}
// void	attack(int keysim, t_sprite spr, t_map *map)