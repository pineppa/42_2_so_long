/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:23 by jsala             #+#    #+#             */
/*   Updated: 2024/01/27 12:41:14 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	free_anima_list(void *mlx, t_anima **anima)
{
	t_anima	*temp;

	while (*anima != NULL)
	{
		temp = *anima;
		*anima = (*anima)->next;
		if (temp->img != NULL)
			mlx_destroy_image(mlx, temp->img);
		free(temp);
	}
}

void	free_object(void *mlx, t_obj *obj)
{
	free_anima_list(mlx, &(obj->anima));
	free(obj);
}

void	free_resources(t_data *game)
{
	free_matrix(game->map->map_content);
	free_object(game->mlx_conn, game->map->p1);
	free_object(game->mlx_conn, game->map->collecs);
	free_object(game->mlx_conn, game->map->exits);
	free_object(game->mlx_conn, game->map->ground);
	free_object(game->mlx_conn, game->map->wall);
//	free_object(game->mlx_conn, game->map->patrol);
	free(game->map);
}
