/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:23 by jsala             #+#    #+#             */
/*   Updated: 2024/03/15 11:22:04 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(t_data *game)
{
	free_map(game);
	mlx_destroy_window(game->mlx_conn, game->window);
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

void	free_anima_list(void *mlx, t_anima **anima)
{
	t_anima	*temp;

	while ((*anima) != NULL)
	{
		temp = *anima;
		if ((*anima)->img)
			mlx_destroy_image(mlx, (*anima)->img);
		if ((*anima)->addr)
			free((*anima)->addr);
		(*anima)->next = NULL;
		free(*anima);
		*anima = temp->next;
	}
}

void	free_object(void *mlx, t_obj *obj)
{
	if (!obj)
		return ;
	free_anima_list(mlx, &(obj->anima));
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
	if (game->map->patrols)
		free_object(game->mlx_conn, game->map->patrols);
	free(game->map);
}
