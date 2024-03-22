/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:20:39 by jsala             #+#    #+#             */
/*   Updated: 2024/03/22 11:14:23 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_mlx(t_data *game)
{
	mlx_key_hook(game->window, handle_key_input, game);
	mlx_hook(game->window, ON_DESTROY, 0, game_exit, game);
	mlx_loop_hook(game->mlx_conn, ft_render, game);
	mlx_loop(game->mlx_conn);
	return (0);
}

void	init_map(t_data *game, char *map_file)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map || !map_file)
	{
		throw_error("Initialisation failure - Map\n");
		game_exit(game, 1);
	}
	game->map->map_content = NULL;
	game->map->exits = NULL;
	game->map->p1 = NULL;
	game->map->collecs = NULL;
	game->map->wall = NULL;
	game->map->ground = NULL;
	if (!load_map(map_file, game->map))
	{
		throw_error("Initialisation failure - Map\n");
		game_exit(game, 1);
	}
}

int	init_game_resources(t_data *game, char *map_file)
{
	init_map(game, map_file);
	init_game_gui_content(game);
	game->mlx_conn = mlx_init();
	if (!game->mlx_conn)
	{
		throw_error("Initialisation failure - Connection");
		game_exit(game, 1);
	}
	game->window = mlx_new_window(game->mlx_conn,
			IMG_W * game->map->map_size.x,
			IMG_H * game->map->map_size.y, "So long");
	if (!game->window)
	{
		throw_error("Initialisation failure - Window");
		game_exit(game, 1);
	}
	if (init_objects(game->mlx_conn, game->map) == 0)
	{
		throw_error("Initialisation failure - Objects");
		game_exit(game, 1);
	}
	game->map->moves = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2 || !ft_check_file_extension(argv[1]))
	{
		throw_error("Insert a single map file with extension .ber\n");
		exit(EXIT_FAILURE);
	}
	init_game_resources(&game, argv[1]);
	handle_mlx(&game);
	game_exit(&game, 0);
}
