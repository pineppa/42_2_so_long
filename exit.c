/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:23 by jsala             #+#    #+#             */
/*   Updated: 2024/02/12 14:40:45 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(t_data *game)
{
	free_map(game);
	printf("Free map;\n");
	mlx_clear_window(game->mlx_conn, game->window);
	mlx_destroy_window(game->mlx_conn, game->window);
	printf("Free window;\n");
	//mlx_destroy_display(game->mlx_conn);
	if (game->mlx_conn)
		free(game->mlx_conn);
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

	while (*anima != NULL)
	{
		temp = *anima;
		*anima = (*anima)->next;
		if (temp->img != NULL)
			mlx_destroy_image(mlx, temp->img);
	}
}

void	free_object(void *mlx, t_obj *obj)
{
	free_anima_list(mlx, &(obj->anima));
	free(obj);
}

void	free_map(t_data *game)
{
	free_matrix(game->map->map_content);
	if (game->map->p1)
		free_object(game->mlx_conn, game->map->p1);
	if (game->map->collecs)
		free_object(game->mlx_conn, game->map->collecs);
	free_object(game->mlx_conn, game->map->exits);
	free_object(game->mlx_conn, game->map->ground);
	free_object(game->mlx_conn, game->map->wall);
	if (game->map->patrols)
		free_object(game->mlx_conn, game->map->patrols);
	free(game->map);
}
