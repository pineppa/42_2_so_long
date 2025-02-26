/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:23 by jsala             #+#    #+#             */
/*   Updated: 2024/02/26 21:42:57 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(t_data *game)
{
	free_resources(game);
	// mlx_clear_window(game->mlx_conn, game->window);
	// mlx_destroy_window(game->mlx_conn, game->window);
	// mlx_destroy_display(game->mlx_conn);
	free(game->mlx_conn);
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

	temp = NULL;
	while ((*anima) != NULL && (*anima)->img != NULL)
	{
		temp = (*anima)->next;
		if ((*anima)->img != NULL)
			mlx_destroy_image(mlx, (*anima)->img);
		(*anima)->img = NULL;
		(*anima) = temp;
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
	if (game->map->p1 != NULL)
		free_object(game->mlx_conn, game->map->p1);
	if (game->map->collecs != NULL){
		free_object(game->mlx_conn, game->map->collecs);}
	if (game->map->exits != NULL)
		free_object(game->mlx_conn, game->map->exits);
	if (game->map->ground != NULL)
		free_object(game->mlx_conn, game->map->ground);
	if (game->map->wall != NULL)
		free_object(game->mlx_conn, game->map->wall);
	if (game->map->patrols != NULL)
		free_object(game->mlx_conn, game->map->patrols);
	if (game->map != NULL)
		free(game->map);
}
