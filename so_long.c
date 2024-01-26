/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:20:39 by jsala             #+#    #+#             */
/*   Updated: 2024/01/26 10:27:57 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_exit(t_data *game)
{
//	free_resources(game);
	mlx_clear_window(game->mlx_conn, game->window);
	mlx_destroy_window(game->mlx_conn, game->window);
}

int ft_render(t_data *game)
{
	mlx_clear_window(game->mlx_conn, game->window);
	draw_game_gui(game, game->map->map_content); // Name to be changed
	printf("I am rendering. %p\n", game->map);
	sleep(1);
	printf("I slept a second!\n");
	return (0);
}

int	handle_mlx(t_data *game)
{
	printf("\n --- handle mlx --- \n\n");
	init_keys(game);
	printf(" --- init keys --- \n");
	mlx_loop_hook(game->mlx_conn, ft_render, game);
	printf(" --- loop hook --- \n");
//	mlx_expose_hook(game->window, &ft_expose, void);
	mlx_loop(game->mlx_conn); //Infinite loop (while(1) that waits for keyboard / mouse signals)
	return (0);
}

int	init_map(t_data *game, char *map_file)
{
	printf("The map_file received is: %s\n", map_file);
	game->map = malloc(sizeof(t_map));
	if (!game->map || !map_file)
		return (0);
	printf("The map_file received is: %s\n", map_file);
	if (!load_map(map_file, game->map))
	{
		free(game->map);
		return (0);
	}
	return (1);
}

int	init_game_resources(t_data *game, char *map_file)
{
	int	res;

	res = init_map(game, map_file);
	if (res == 0)
	{
		throw_error("Initialisation failure - Map\n");
		return (0);
	}
	printf("Init debug get info:\n- Pointer game: %p;\n- Map file: %s;\n", game, map_file);
	res = init_game_gui(game);
	if (res == 0)
	{
		throw_error("Initialisation failure - Game GUI\n");
		return (0);
	}
	return (1);
}

int	init_game(t_data *game)
{
	game->mlx_conn = mlx_init(); //Sets up a connection to the X Server
	if (!game->mlx_conn)
		return (0); //Shall it throw an error?
	game->window = mlx_new_window(game->mlx_conn, WIN_W, WIN_H, "So long");
	if (!game->window)
		return (0); //Shall it throw an error and free game->mlx_conn?
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*game;
	int		res;

	if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) //Doesn't block fake names, should check the file extension and MIME file
	{
		ft_putstr_fd("Correct input format: $>so_long *.ber.\n", 1);
		return (EXIT_FAILURE);
	}
	game = malloc(sizeof(t_data));
	if (!game)
		return (EXIT_FAILURE);
	res = init_game(game);
	if (!res)
		return (EXIT_FAILURE);
	res = init_game_resources(game, argv[1]); // Create a free resources, that checks if there is content, in case it frees it, otherwise goes next
	if (!res)
		return (EXIT_FAILURE); // This should properly free resources
	res = handle_mlx(game);
	if(!res)
		return (EXIT_FAILURE);
	game_exit(game);
	return (EXIT_SUCCESS);
}
