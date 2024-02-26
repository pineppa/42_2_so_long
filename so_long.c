/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:20:39 by jsala             #+#    #+#             */
/*   Updated: 2024/02/26 20:30:36 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_mlx(t_data *game)
{
	init_keys(game);
	mlx_hook(game->window, ON_DESTROY, 0, game_exit, game);
	mlx_loop_hook(game->mlx_conn, ft_render, game);
//	mlx_expose_hook(game->window, &ft_expose, void);
	mlx_loop(game->mlx_conn);
	return (0);
}

int	init_map(t_data *game, char *map_file)
{
	int	screen_w;
	int	screen_h;

	screen_h = 0;
	screen_w = 0;
	mlx_get_screen_size(game->mlx_conn, &screen_w, &screen_h);
	game->map = malloc(sizeof(t_map));
	if (!game->map || !map_file)
		return (0);
	if (!load_map(map_file, game->map)
		|| game->map->map_size.x > screen_w / IMG_W
		|| game->map->map_size.y > screen_h / IMG_H)
	{
		free(game->map);
		return (0);
	}
	return (1);
}

int	init_game_resources(t_data *game, char *map_file)
{
	game->mlx_conn = mlx_init(); //Sets up a connection to the X Server
	if (!game->mlx_conn)
		return (0); //Shall it throw an error?  WIN_W, WIN_H//
	if (init_map(game, map_file) == 0)
	{
		throw_error("Initialisation failure - Map\n");
		return (0);
	}
	game->window = mlx_new_window(game->mlx_conn,
			IMG_W * game->map->map_size.x,
			IMG_H * game->map->map_size.y, "So long");
	if (!game->window)
		return (0);
	if (init_game_gui(game) == 0)
	{
		throw_error("Initialisation failure - Game GUI\n");
		return (0);
	}
	game->map->moves = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*game;

	if (argc != 2 || !ft_check_file_extension(argv[1]))
		return (EXIT_FAILURE);
	game = malloc(sizeof(t_data));
	if (!game)
		return (EXIT_FAILURE);
	if (!init_game_resources(game, argv[1]))
		return (EXIT_FAILURE); // This should properly free resources
	if (!handle_mlx(game))
		return (EXIT_FAILURE);
	game_exit(game);
	return (EXIT_SUCCESS);
}
