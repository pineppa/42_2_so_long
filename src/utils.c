/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:49:01 by jsala             #+#    #+#             */
/*   Updated: 2024/03/20 15:37:34 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
}

void	throw_error(char *message)
{
	perror("Error");
	ft_putstr_fd(message, 2);
	write(2, "\n", 1);
}

int	ft_check_file_extension(char *str)
{
	int	l_str;

	l_str = ft_strlen(str);
	if (l_str < 5)
	{
		throw_error("Correct input format: $>so_long *.ber.\n");
		return (0);
	}
	return (str[l_str - 4] == '.' && str[l_str - 3] == 'b'
		&& str[l_str - 2] == 'e' && str[l_str - 1] == 'r');
}

int init_nr_objs(t_map *map, t_pos *p1_pos)
{
	int		i;
	int		j;

	j = -1;
	map->n_collecs = 0;
	map->n_exits = 0;
	while (map->map_content[++j])
	{
		i = -1;
		while (map->map_content[j][++i])
		{
			if (map->map_content[j][i] == 'E')
				map->n_exits += 1;
			else if (map->map_content[j][i] == 'C')
				map->n_collecs += 1;
			else if (map->map_content[j][i] == 'P')
			{
				if (p1_pos-> x != 0)
					return (0);
				p1_pos->x = i;
				p1_pos->y = j;
			}
		}
	}
	return (p1_pos->x != 0	&& map->n_collecs > 0 && map->n_exits > 0);
}
