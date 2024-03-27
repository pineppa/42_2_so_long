/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:25 by jsala             #+#    #+#             */
/*   Updated: 2024/03/27 11:18:02 by jsala            ###   ########.fr       */
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
	anima->next = NULL;
	return (anima);
}

t_anima *load_anima(void *mlx, char *img_file, t_anima *anima)
{
	t_anima *temp;
	int		i;
	char	*file_path;

	i = 0;
	temp = anima;
	while (++i < FRAMES_ANIMA)
	{
		file_path = get_file_path(img_file, i);
		temp->next = load_img(mlx, file_path);
		temp = temp->next;
		free(file_path);
	}
	temp->next = anima;
	return (anima);
}

t_obj	*load_obj(void *mlx, char *img_file, char obj_char)
{
	t_obj	*item;

	item = ft_calloc(sizeof(t_obj), 1);
	if (!item)
		return (NULL);
	item->anima = load_img(mlx, img_file);
	if (obj_char == 'P' || obj_char == 'D')
		item->anima = load_anima(mlx, img_file, item->anima);
	if (!item->anima)
		return (NULL);
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
	map->patrols = load_obj(mlx, PATROL_IMG, 'D');
	if (map->wall == NULL || map->collecs == NULL
		|| map->ground == NULL || map->patrols == NULL
		|| map->exits == NULL || map->p1 == NULL)
	{
		throw_throw_error(" Failed to load image");
		return (0);
	}
	return (1);
}

int	init_game_gui(t_data *game)
{
	if (init_objects(game->mlx_conn, game->map) == 0)
	{
		throw_throw_error(" Initialisation failure - Images");
		return (0);
	}
	if (!init_nr_objs(game->map))
	{
		throw_throw_error(" Map does not contain the minimum elements");
		game_exit(game, 1);
	}
	if (!check_valid_path(game->map))
		return (0);
	draw_game_map(game, game->map);
	return (1);
}
