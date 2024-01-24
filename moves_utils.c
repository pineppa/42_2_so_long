/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:50 by jsala             #+#    #+#             */
/*   Updated: 2024/01/24 18:55:14 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_move_inbound(char **map, int x, int y)
{
	if (x < 1 || y < 1
		|| y > ((int)ft_strlen(map) - 1)
		|| x > ((int)ft_strlen(map[0]) - 1)) // Should not be necessary, but better check 
		return (0);
	return (1);
}

int	is_move_wall(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (1);
	return (0);
}

int is_player_exit(char **map, int x, int y)
{
    if (map[y][x] == 'E')
    {
        if (game->collectibles == all)
            printf("Win!");
            //exit... return(1);
        else
        //Ignore the exit or say you lose
    }
    return (0);
}

int is_player_collect(char **map, int x, int y)
{
    if (map[y][x] == 'C')
    {
        printf("1 UP!");
        //exit... return(1);
    }
    return (0);
}

int is_player_patrol(char **map, int x, int y)
{
    if (map[y][x] == 'Patrol')
    {
        printf("Game lost");
        //play lost sound;
        //exit... return(1);
    }
    return (0);
}