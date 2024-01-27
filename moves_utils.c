/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:50 by jsala             #+#    #+#             */
/*   Updated: 2024/01/27 12:06:37 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_move_inbound(t_pos map_size, int x, int y)
{
	return (x > 0 && y > 0
		&& y < map_size.y && x < map_size.x); // Should not be necessary, but better check ;
}

int	is_move_wall(char **map, int x, int y)
{
	return (map[y][x] == '1');
}

int	is_player_exit(char **map, int x, int y)
{
	if (map[y][x] == 'E')
	{
		//if (game->collectibles == all)
		printf("Win!");
		return (1);
		//else
		//Ignore the exit or say you lose
	}
	return (0);
}

int	is_player_collect(char **map, int x, int y)
{
	if (map[y][x] == 'C')
	{
		printf("1 UP!");
		//exit... return(1);
	}
	return (0);
}
/*
int	is_player_patrol(char **map, int x, int y)
{
	if (map[y][x] == 'Patrol')
	{
		printf("Game lost");
		//play lost sound;
		//exit... return(1);
	}
	return (0);
}
*/
