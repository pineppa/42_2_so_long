/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:25 by jsala             #+#    #+#             */
/*   Updated: 2024/01/23 22:09:11 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*load_img(t_data *game, char *img_file) // --> This only loads it, doesn't show it yet 
{
	t_image	*img;

	img = malloc(sizeof(t_image *)); // How? And should it be done? 
	if (img == NULL)
		return (0);
	img->length = 1080;
	img->width = 1920;
	img->img = mlx_xpm_file_to_image(game->mlx_conn, img_file, 
		&(img->width), &(img->length)); // To be fixed in size;
	// img->img = mlx_new_image(game->mlx_conn, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	return (img);
}
/*
void	draw_game_gui(t_data *game)
{
	dst = img->addr + (img_pos.y * img->line_length + img_pos.x * (img->bpp / 8));
	*(unsigned int*)dst = color; // Why this? It transforms the integer in a pointer with the RGBA structure 0x00FFBB00
	while ()
	{
		mlx_put_image_to_window(game->mlx_conn, game->window, img.img, img_pos.x, img_pos.y);
	}
}*/
int	init_images(t_data *game)
{
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
	*/  /*
	init_images(game);
	if (not loaded)
	{
		free(all);
		throw_error("Error loading images");
	}
	draw_game_gui(game);	*/
	printf("%p\n", game->mlx_conn);
	return (1);
}
