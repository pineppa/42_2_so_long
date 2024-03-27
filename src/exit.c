/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:23 by jsala             #+#    #+#             */
/*   Updated: 2024/03/27 10:45:44 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(t_data *game, int exit_id)
{
	if (game->map)
		free_map(game);
	if (game->window)
		mlx_destroy_window(game->mlx_conn, game->window);
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
	{
		if (matrix[i])
		{
			free(matrix[i]);
			matrix[i] = NULL;
		}
	}
	free(matrix);
	matrix = NULL;
}

void	free_object(void *mlx, t_obj *obj)
{
	if (!obj)
		return ;
	if (obj->anima->img)
		mlx_destroy_image(mlx, obj->anima->img);
	if (obj->anima)
	{
		free(obj->anima);
		obj->anima = NULL;
	}
	free(obj);
	obj = NULL;
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
	game->map = NULL;
}
