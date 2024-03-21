/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:25 by jsala             #+#    #+#             */
/*   Updated: 2024/03/21 15:47:53 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_anima	*load_img(void *mlx, char *img_file)
{
	t_anima	*anima;

	anima = ft_calloc(sizeof(t_anima), 1);
	if (anima == NULL)
		return (0);
	anima->img = NULL;
	anima->h = 64;
	anima->w = 64;
	anima->img = mlx_xpm_file_to_image(mlx, img_file,
			&(anima->w), &(anima->h));
	return (anima);
}

t_obj	*load_obj(void *mlx, char *img_file, char obj_char)
{
	t_obj	*item;

	item = ft_calloc(sizeof(t_obj), 1);
	if (!item)
		return (NULL);
	item->anima = load_img(mlx, img_file);
	item->pos.x = 0;
	item->pos.y = 0;
	item->obj_char = obj_char;
	return (item);
}

int	init_objects(void *mlx, t_map *map)
{
	map->wall = load_obj(mlx, WALL_IMG, '0');
	map->ground = load_obj(mlx, GROUND_IMG, '1');
	map->collecs = load_obj(mlx, COLLECTIBLE_IMG, 'C');
	map->p1 = load_obj(mlx, PLAYER_IMG, 'P');
	map->exits = load_obj(mlx, EXIT_IMG, 'E');
	if (map->wall == NULL || map->collecs == NULL
		|| map->ground == NULL
		|| map->exits == NULL || map->p1 == NULL)
	{
		throw_error("Failed to load image\n");
		return (0);
	}
	return (1);
}

void	init_game_gui_content(t_data *game)
{
	t_pos	p1_pos;

	p1_pos.x = 0;
	p1_pos.y = 0;
	if (!init_nr_objs(game->map, &p1_pos))
	{
		throw_error("Map does not contain the minimum elements\n");
		game_exit(game, 1);
	}
	if (!check_valid_path(game->map, p1_pos))
	{
		throw_error("Initialisation failure - Game GUI\n");
		game_exit(game, 1);
	}
}
