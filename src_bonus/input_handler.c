/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:25:44 by jsala             #+#    #+#             */
/*   Updated: 2024/03/21 15:47:53 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_input(int keysim, t_data *game)
{
	if (keysim == ESC)
		game_exit(game, 1);
	else if (keysim == UP || keysim == RIGHT || keysim == LEFT
		|| keysim == DOWN || keysim == W || keysim == D
		|| keysim == A || keysim == S)
		{
			if(move(keysim, game->map->p1, game->map) == 0)
				game_exit(game, 1);
		}
/*	else if (keysim == SHOOT)
		shoot()*/
	return (0);
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
