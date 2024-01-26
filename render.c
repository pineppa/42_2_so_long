/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:43:04 by jsala             #+#    #+#             */
/*   Updated: 2024/01/26 14:22:48 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_render(t_data *game)
{
	mlx_clear_window(game->mlx_conn, game->window);
	draw_game_gui(game, game->map); // Name to be changed
	mlx_do_sync(game->mlx_conn);
	return (0);
}

void	draw_game_gui(t_data *game, t_map *map)
{
	t_pos	pos;

	pos.x = -1;
	pos.y = -1;
	while (++pos.y < game->map->map_size.y)
	{
		while(++pos.x < game->map->map_size.x)
		{
			if (map->map_content[pos.y][pos.x] == 'E')
				draw_item(game, map->exits, pos);
			else if (map->map_content[pos.y][pos.x] == 'C')
				draw_item(game, map->collecs, pos);
			else if (map->map_content[pos.y][pos.x] == '0')
				draw_item(game, map->ground, pos);
			else if (map->map_content[pos.y][pos.x] == '1')
				draw_item(game, map->wall, pos);
			else if (map->map_content[pos.y][pos.x] == 'P')
				draw_item(game, map->p1, pos);
		//	else if (map[pos.y][pos.x] == 'Patrol')
		//		draw_item(game, map->wall, pos);	
		}
		pos.x = -1;
	}
}

int draw_item(t_data *game, t_obj *item, t_pos pos)
{
	if (item->obj_char == 'E' || item->obj_char == 'P' || item->obj_char == 'C')
		mlx_put_image_to_window(game->mlx_conn, game->window, 
			item->anima->img, IMG_W * pos.x, IMG_H * pos.y);
	mlx_put_image_to_window(game->mlx_conn, game->window, item->anima->img,
		IMG_W * pos.x, IMG_H * pos.y);
	if (item->obj_char == 'P') 
	{
		item->pos.x = pos.x;
		item->pos.y = pos.y;
	}
	return (1);
}