/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:25:44 by jsala             #+#    #+#             */
/*   Updated: 2024/03/21 18:00:47 by jsala            ###   ########.fr       */
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
		if (move(keysim, game->map->p1, game->map) == 0)
			game_exit(game, 1);
	}
	return (0);
}

int	init_keys(t_data *game)
{
	mlx_key_hook(game->window, handle_key_input, game);
	return (1);
}
