/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:25:44 by jsala             #+#    #+#             */
/*   Updated: 2024/01/24 20:09:13 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Mac uses keycodes, while linux uses keysim!
int handle_key_input(int keysim, t_data *game) // How is data working?
{
	if (keysim == ESC)
	{
		// popup_menu
		return (EXIT_SUCCESS); // To be fixed;
	}
	else if (keysim == UP || keysim == RIGHT || keysim == LEFT
		|| keysim == DOWN || keysim == W || keysim == D 
		|| keysim == A || keysim == S)
		move(keysim, game->map->spr_p[0], game->map);
/*	else if (keysim == SHOOT)
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

*/
int init_keys(t_data *game)
{
	mlx_key_hook(game->window, &handle_key_input, game); // Pass info about key hook
//	mlx_mouse_hook(game->window, &handle_mouse_input, game); // Left, Right, Middle, Scroll Up, Scroll Down
	return(1);
}