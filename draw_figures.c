/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:57:33 by jsala             #+#    #+#             */
/*   Updated: 2024/01/26 10:09:47 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int draw_static_item(t_data *game, t_item *item, int x, int y)
{
	mlx_put_image_to_window(game->mlx_conn, game->window, item->img,
		IMG_W * x, IMG_H * y);
	return (1);
}

int draw_dyn_item(t_data *game, t_item *item, int x, int y)
{
	mlx_put_image_to_window(game->mlx_conn, game->window, item->img,
		IMG_W * x, IMG_H * y);
	return (1);
}
