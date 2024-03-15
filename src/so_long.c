/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:20:39 by jsala             #+#    #+#             */
/*   Updated: 2024/03/15 13:30:48 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_mlx(t_data *game)
{
	init_keys(game);
	mlx_hook(game->window, ON_DESTROY, 0, game_exit, game);
	mlx_loop_hook(game->mlx_conn, ft_render, game);
	mlx_loop(game->mlx_conn);
	return (0);
}

int	init_map(t_data *game, char *map_file)
{
	game->map = ft_calloc(sizeof(t_map), 1);
	if (!game->map || !map_file)
		game_exit(game); // Changed
	game->map->map_content = NULL;
	game->map->exits = NULL;
	game->map->p1 = NULL;
	game->map->collecs = NULL;
	game->map->wall = NULL;
	game->map->ground = NULL;
		if (!load_map(map_file, game->map))
	{
		game_exit(game);
	//	return (0);
	}
	return (1);
}

int	init_game_resources(t_data *game, char *map_file)
{
	int	res;

	game->mlx_conn = mlx_init();
	if (!game->mlx_conn)
		game_exit(game); // Changed
	res = init_map(game, map_file);
	if (res == 0)
	{
		throw_error("Initialisation failure - Map\n");
		game_exit(game); // Changed -- Consider removing the other function and joining the two
	}
	game->window = mlx_new_window(game->mlx_conn,
			IMG_W * game->map->map_size.x,
			IMG_H * game->map->map_size.y, "So long");
	if (!game->window)
		game_exit(game); // Changed
	res = init_game_gui(game);
	if (res == 0)
	{
		throw_error("Initialisation failure - Game GUI\n");
		game_exit(game); // Changed
	}
	game->map->moves = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*game;
	int		res;

	if (argc != 2 || !ft_check_file_extension(argv[1]))
		return (1);
	game = ft_calloc(sizeof(t_data), 1);
	if (!game)
		return (0);
	game->map = NULL;
	game->window = NULL;
	game->mlx_conn = NULL;
	res = init_game_resources(game, argv[1]); // Res should be deleteable
	if (!res)
		game_exit(game);
	res = handle_mlx(game); // This can't handle any failure at this moment
	if (!res)
		game_exit(game);
	game_exit(game);
}
