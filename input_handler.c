/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:25:44 by jsala             #+#    #+#             */
/*   Updated: 2024/01/27 12:08:45 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Mac uses keycodes, while linux uses keysim!
int	handle_key_input(int keysim, t_data *game) // How is data working?
{
	int	res;

	res = 0;
	if (keysim == ESC)
	{
		game_exit(game);
		exit(EXIT_SUCCESS); // To be fixed to exit loop;
	}
	else if (keysim == UP || keysim == RIGHT || keysim == LEFT
		|| keysim == DOWN || keysim == W || keysim == D
		|| keysim == A || keysim == S)
		res = move(keysim, game->map->p1, game->map); // Moves can be here, but potentially need space
/*	else if (keysim == SHOOT)
		shoot()*/
	return (res);
}

/*
int handle_mouse_input(int keysim, t_data *game)
{

}

// mlx_hook() allows to select the signal_hook better connection for functions
*/
int	init_keys(t_data *game)
{
	mlx_key_hook(game->window, handle_key_input, game); // Pass info about key hook
//	mlx_mouse_hook(game->window, &handle_mouse_input, game); // Left, Right, Middle, Scroll Up, Scroll Down
	return (1);
}
