/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:20:39 by jsala             #+#    #+#             */
/*   Updated: 2024/03/27 11:18:02 by jsala            ###   ########.fr       */
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
	game->map = ft_calloc(sizeof(t_map), 1);
	if (!game->map || !map_file)
		return (0);
	if (!load_map(map_file, game->map))
	{
		game_exit(game, 1);
		return (0);
	}
	return (1);
}

int	init_game_resources(t_data *game, char *map_file)
{
	int	res;

	game->mlx_conn = mlx_init();
	if (!game->mlx_conn)
		return (0);
	res = init_map(game, map_file);
	if (res == 0)
	{
		throw_throw_error(" Initialisation failure - Map\n");
		return (0);
	}
	game->window = mlx_new_window(game->mlx_conn,
			IMG_W * game->map->map_size.x,
			IMG_H * game->map->map_size.y, "So long");
	if (!game->window)
		return (0);
	res = init_game_gui(game);
	if (res == 0)
	{
		throw_throw_error(" Initialisation failure - Game GUI\n");
		return (0);
	}
	game->map->moves = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*game;
	int		res;

	if (argc != 2 || !ft_check_file_extension(argv[1]))
		return (EXIT_FAILURE);
	game = ft_calloc(sizeof(t_data), 1);
	if (!game)
		return (EXIT_FAILURE);
	res = init_game_resources(game, argv[1]);
	if (!res)
		return (EXIT_FAILURE);
	res = handle_mlx(game);
	if (!res)
		return (EXIT_FAILURE);
	game_exit(game, 1);
}
