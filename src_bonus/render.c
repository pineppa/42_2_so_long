/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:43:04 by jsala             #+#    #+#             */
/*   Updated: 2024/03/12 08:41:06 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int draw_item(t_data *game, t_obj *item, t_pos pos)
{
	mlx_put_image_to_window(game->mlx_conn, game->window, item->anima->img,
		IMG_W * pos.x, IMG_H * pos.y);
	if (item->obj_char == 'P' || item->obj_char == 'D')
	{
		item->pos.x = pos.x;
		item->pos.y = pos.y;
		item->anima = item->anima->next;
	}
	return (1);
}

void	draw_game_map(t_data *game, t_map *map)
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
			else if (map->map_content[pos.y][pos.x] == 'D')
				draw_item(game, map->patrols, pos);
		}
		pos.x = -1;
	}
}

int	draw_moves(t_data *game)
{
	char	*moves_text;

	moves_text = ft_itoa(game->map->moves);
	mlx_string_put(game->mlx_conn, game->window, IMG_W / 4, IMG_H / 4,
		TEXT_COLOR, "Moves:");
	mlx_string_put(game->mlx_conn, game->window, IMG_W / 4, 3 * IMG_H / 4,
		TEXT_COLOR, moves_text);
	if (moves_text)
		free(moves_text);
	return (0);
}

int	draw_ui(t_data *game)
{
	draw_moves(game);
	return (0);
}

int ft_render(t_data *game)
{
	mlx_clear_window(game->mlx_conn, game->window);
	draw_game_map(game, game->map);
	draw_ui(game);
	usleep(75000);
	mlx_do_sync(game->mlx_conn);
	return (0);
}
