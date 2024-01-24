/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:20:39 by jsala             #+#    #+#             */
/*   Updated: 2024/01/23 22:07:59 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	game_exit(t_data *game)
{
	free_resources(game);
	mlx_clear_window(game->window);
	mlx_destroy_window(game->window);
}
*/

void	handle_mlx(t_data *game)
{
	t_pos	img_pos;
	
	game->mlx_conn = mlx_init(); //Sets up a connection to the X Server
	if (!game->mlx_conn)
		return (1); //Shall it throw an error?
	game->window = mlx_new_window(game->mlx_conn, 1920, 1080, "So long");
	if (!game->window)
		return (1); //Shall it throw an error and free game->mlx_conn?
	init_game_gui(game);
	init_keys(game);
//	mlx_expose_hook(game->window, &ft_expose, void);
//	mlx_loop(game->mlx_conn); //Infinite loop (while(1) that waits for keyboard / mouse signals)
//	game_exit(game);
}

int	init_map(t_data *game, char *map_file)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map || !map_file)
		return (1);
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
		throw_error("Initialisation failure - Map");
		return (0);
	}
	res = init_images(game);
	if (res == 0)
	{
		throw_error("Initialisation failure - Images");
		return (0);
	}
	res = init_game_gui(game);
	if (res == 0)
	{
		throw_error("Initialisation failure - Game GUI");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*game;
	int			res;

	if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) //Doesn't block fake names, should check the file extension and MIME file
	{
		write(1, "Correct input format: $>so_long *.ber.", 38);
		return (1);
	}
	game = malloc(sizeof(t_data *));
	if (!game)
		return (1);
	res = init_game_resources(game, argv[2]); // Create a free resources, that checks if there is content, in case it frees it, otherwise goes next
	if (!res)
		return (1); // This should properly free resources
	// handle_mlx();
	// free_resources(game);
	return (0);
}
