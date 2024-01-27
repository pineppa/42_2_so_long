/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:25 by jsala             #+#    #+#             */
/*   Updated: 2024/01/27 12:45:20 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_anima	*load_img(void *mlx, char *img_file)
{
	t_anima	*anima;

	anima = malloc(sizeof(t_anima));
	if (anima == NULL)
		return (0);
	anima->img = NULL;
	anima->h = 64;
	anima->w = 64;
	anima->img = mlx_xpm_file_to_image(mlx, img_file,
			&(anima->w), &(anima->h));
	anima->addr = mlx_get_data_addr(anima->img, &anima->bpp,
			&anima->line_length, &anima->endian);
	anima->next = NULL;
	return (anima);
}

t_obj	*load_obj(void *mlx, char *img_file, char obj_char)
{
	t_obj	*item;

	item = malloc(sizeof(t_obj));
	if (!item)
		return (NULL);
	item->anima = load_img(mlx, img_file);
	if (!item->anima)
		return (NULL);
	item->pos.x = 0;
	item->pos.y = 0;
	item->obj_char = obj_char;
	return (item);
}

int	init_objects(void *mlx, t_map *map)
{
	printf("\n --- Starting to load images --- \n\n");
	map->wall = load_obj(mlx, WALL_IMG, '0');
	map->ground = load_obj(mlx, GROUND_IMG, '1');
	map->collecs = load_obj(mlx, COLLECTIBLE_IMG, 'C');
	map->p1 = load_obj(mlx, PLAYER_IMG, 'P');
	map->exits = load_obj(mlx, EXIT_IMG, 'E');
//	map->patrols = load_img(mlx, PATROL_IMG);
	if (map->wall == NULL || map->collecs == NULL
		|| map->ground == NULL //|| map->patrols == NULL
		|| map->exits == NULL || map->p1 == NULL)
	{
		throw_error("Failed to load image");
		return (0);
	}
	return (1);
}

int	init_game_gui(t_data *game)
{
	if (init_objects(game->mlx_conn, game->map) == 0)
	{
		throw_error("Initialisation failure - Images");
		return (0);
	}
	draw_game_gui(game, game->map);
	return (1);
}
