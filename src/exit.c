/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:23 by jsala             #+#    #+#             */
/*   Updated: 2024/03/14 13:02:18 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(t_data *game)
{
	mlx_destroy_window(game->mlx_conn, game->window);
	free_map(game);
//	if (game->mlx_conn)
//		free(game->mlx_conn);
	if(game)
		free(game);
	exit(EXIT_SUCCESS);
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
