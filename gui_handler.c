/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:25 by jsala             #+#    #+#             */
/*   Updated: 2024/01/26 14:45:48 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_anima	*load_img(void *mlx, char *img_file) // --> This only loads it, doesn't show it yet 
{
	t_anima	*anima;

	anima = malloc(sizeof(t_anima)); // How? And should it be done? 
	if (anima == NULL)
		return (0);
	anima->img = NULL;
	printf("Image file name: %s; What is mlx? %p\n", img_file, mlx);
	anima->h = 64;
	anima->w = 64;
	printf("Image file name: %s; Sizes: %i, %i;\n", img_file, anima->h, anima->w);
	anima->img = mlx_xpm_file_to_image(mlx, img_file, 
		&(anima->w), &(anima->h)); // To be fixed in size;
	printf("Image file name: %s; Image loaded?\n", img_file);
	anima->addr = mlx_get_data_addr(anima->img, &anima->bpp, 
		&anima->line_length, &anima->endian);
	printf("Image file name: %s; Image addressed?\n", img_file);
	return (anima);
}

t_obj *load_obj(void *mlx, char *img_file, char obj_char)
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
	//map->patrols = load_img(mlx, PATROL_IMG);
	if (map->wall == NULL || map->collecs == NULL 
		|| map->ground == NULL //|| map->patrols == NULL
		|| map->exits == NULL || map->p1 == NULL)
	{
		throw_error("Failed to load image");
		return(0);
	}
	return (1);
}
int init_game_gui(t_data *game)
{
	/* map->map_size tells how big the matrix of map is. This should be used to manage the content in the window;
	- To be checked if the window can be set with a minimum and maximum size... 
	- How should the images be handled not to be stretched?
	- Should the background be loaded as a single image?
	Go through map and load every location with the specific image required:
	- 0 Loads the ground space;
	- 1 Loads the Wall image;
	- ECP loads an ground space as background plus the specific image that represents the Exit, a Collectible, or the Player;

	Map here is already loaded beforehand
	*/
	if (init_objects(game->mlx_conn, game->map) == 0)
	{
		throw_error("Initialisation failure - Images");
		return (0);
	}
	draw_game_gui(game, game->map);
	//mlx_put_anima_to_window(game->mlx_conn, game->window, game->img_wall, 0, 0);
	//mlx_put_anima_to_window(game->mlx_conn, game->window, game->img_ground, 150, 150);
	//mlx_put_anima_to_window(game->mlx_conn, game->window, game->img_wall, 0, 150);
	return (1);
}
