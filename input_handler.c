/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:25:44 by jsala             #+#    #+#             */
/*   Updated: 2024/01/25 18:47:49 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Mac uses keycodes, while linux uses keysim!
int handle_key_input(int keysim, t_data *game) // How is data working?
{
	printf("Value of key: %i, pointer %p\n", keysim, game);
	if (keysim == ESC)
	{
		printf("Value of key: %i\n", keysim);
		printf("Exit on going!");
		return (EXIT_SUCCESS); // To be fixed to exit loop;
	}
/*	else if (keysim == UP || keysim == RIGHT || keysim == LEFT
		|| keysim == DOWN || keysim == W || keysim == D 
		|| keysim == A || keysim == S)
		move(keysim, game->map->obj_p[0], game->map); // Moves can be here, but potentially need space
*//*	else if (keysim == SHOOT)
		shoot()
*/	
	return (1);
}
/*
int handle_mouse_input(int keysim, t_data *game)
{

}

_expose_hook;
_loop_hook;
// mlx_hook() allows to select the signal_hook better connection for functions
*/
int init_keys(t_data *game)
{
	mlx_key_hook(game->window, handle_key_input, game); // Pass info about key hook
//	mlx_mouse_hook(game->window, &handle_mouse_input, game); // Left, Right, Middle, Scroll Up, Scroll Down
	return(1);
}