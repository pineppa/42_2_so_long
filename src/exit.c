/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:23 by jsala             #+#    #+#             */
/*   Updated: 2024/03/21 15:48:19 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(t_data *game, int exit_id)
{
	if (game->window)
		mlx_destroy_window(game->mlx_conn, game->window);
	if (game->map)
		free_map(game);
	if (game)
		free(game);
	if (exit_id == 0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	free_object(void *mlx, t_obj *obj)
{
	if (!obj)
		return ;
	mlx_destroy_image(mlx, obj->anima->img);
	free(obj->anima);
	free(obj);
}

void	free_map(t_data *game)
{
	if (game->map->map_content)
		free_matrix(game->map->map_content);
	if (game->map->p1)
		free_object(game->mlx_conn, game->map->p1);
	if (game->map->collecs)
		free_object(game->mlx_conn, game->map->collecs);
	if (game->map->exits)
		free_object(game->mlx_conn, game->map->exits);
	if (game->map->ground)
		free_object(game->mlx_conn, game->map->ground);
	if (game->map->wall)
		free_object(game->mlx_conn, game->map->wall);
	free(game->map);
}
