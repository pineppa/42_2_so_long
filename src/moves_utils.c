/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:50 by jsala             #+#    #+#             */
/*   Updated: 2024/03/21 17:59:20 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_exit(t_map *map)
{
	if (map->n_collecs == 0)
	{
		printf("Win!\n");
		return (0);
	}
	else
		printf("Not all mushrooms were collected\n");
	return (1);
}

int	player_collect(t_map *map)
{
	printf("1 UP!\n");
	if (!(map->n_collecs > 0))
		throw_error("Collectionables should be gone by now\n");
	map->n_collecs -= 1;
	return (0);
}
