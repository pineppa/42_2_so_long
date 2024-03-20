/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:08:13 by jsala             #+#    #+#             */
/*   Updated: 2024/03/20 15:37:52 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_obj	*update_obj_pos(t_map *map, t_obj *obj, t_pos new_pos)
{
	char	*itoa_val;

	map->map_content[new_pos.y][new_pos.x] = obj->obj_char;
	map->map_content[obj->pos.y][obj->pos.x] = '0';
	obj->pos.x = new_pos.x;
	obj->pos.y = new_pos.y;
	map->moves += 1;
	ft_putstr_fd("Current number of moves: ", 1);
	itoa_val = ft_itoa(map->moves); // Is this missing a protection?
	if (!itoa_val)
		return (NULL);
	ft_putstr_fd(itoa_val, 1);
	if (itoa_val)
		free(itoa_val);
	ft_putstr_fd(";\n", 1);
	return (obj);
}

int	move_action(t_map *map, t_obj *obj, t_pos new_pos)
{
	char obj_c;

	obj_c = map->map_content[new_pos.y][new_pos.x];
	if (obj_c == '1')
		return (1);
	else if (obj_c == 'C')
		player_collect(map);
	else if (obj_c == 'E')
		return (player_exit(map));
	update_obj_pos(map, obj, new_pos);
	return (1);
}

int	move(int keysim, t_obj *obj, t_map *map)
{
	t_pos	new_pos;

	new_pos.x = obj->pos.x;
	new_pos.y = obj->pos.y;
	if (keysim == UP || keysim == W)
		new_pos.y -= 1;
	else if (keysim == DOWN || keysim == S)
		new_pos.y += 1;
	else if (keysim == LEFT || keysim == A)
		new_pos.x -= 1;
	else if (keysim == RIGHT || keysim == D)
		new_pos.x += 1;
	return (move_action(map, obj, new_pos));
}
