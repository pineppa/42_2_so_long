/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:25 by jsala             #+#    #+#             */
/*   Updated: 2024/01/25 18:39:04 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_item	*load_img(void *mlx_conn, char *img_file) // --> This only loads it, doesn't show it yet 
{
	t_item	*img;

	img = malloc(sizeof(t_item)); // How? And should it be done? 
	if (img == NULL)
		return (0);
	img->img = NULL;
	printf("Image file name: %s; What is mlx? %p\n", img_file, mlx_conn);
	img->h = 150;
	img->w = 150;
	printf("Image file name: %s; Sizes: %i, %i;\n", img_file, img->h, img->w);
	img->img = mlx_xpm_file_to_image(mlx_conn, img_file, 
		&(img->w), &(img->h)); // To be fixed in size;
	printf("Image file name: %s; Image loaded?\n", img_file);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	printf("Image file name: %s; Image addressed?\n", img_file);
	return (img);
}
/*
void	draw_game_gui(t_data *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	//dst = img->addr + (img_pos.y * img->line_length + img_pos.x * (img->bpp / 8));
	// *(unsigned int*)dst = color; // Why this? It transforms the integer in a pointer with the RGBA structure 0x00FFBB00
	while (map[++i])
	{
		while(map[i][++j])
		{
			mlx_put_item_to_window(game->mlx_conn, game->window, img->img, img.x, img.y);
		}
		i = 0
	}
}
*/
int	init_items(t_data *game)
{
	printf("\n --- Starting to load images --- \n\n");
	game->img_wall = load_img(game->mlx_conn, WALL_IMG);
	game->img_empty = load_img(game->mlx_conn, EMPTY_IMG);
	game->img_collectible = load_img(game->mlx_conn, COLLECTIBLE_IMG);
	game->img_player = load_img(game->mlx_conn, PLAYER_IMG);
	game->img_exit = load_img(game->mlx_conn, EXIT_IMG);
	game->img_patrol = load_img(game->mlx_conn, PATROL_IMG);
	if (game->img_wall == NULL || game->img_collectible == NULL 
		|| game->img_empty == NULL || game->img_patrol == NULL
		|| game->img_exit == NULL || game->img_player == NULL)
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
	- 0 Loads the empty space;
	- 1 Loads the Wall image;
	- ECP loads an empty space as background plus the specific image that represents the Exit, a Collectible, or the Player;

	Map here is already loaded beforehand
	*/
	if (init_items(game) == 0)
	{
		throw_error("Initialisation failure - Images");
		return (0);
	}
	// draw_game_gui(game);
	//mlx_put_item_to_window(game->mlx_conn, game->window, game->img_wall, 0, 0);
	//mlx_put_item_to_window(game->mlx_conn, game->window, game->img_empty, 150, 150);
	//mlx_put_item_to_window(game->mlx_conn, game->window, game->img_wall, 0, 150);
	return (1);
}
