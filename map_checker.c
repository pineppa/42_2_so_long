/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:51:15 by jsala             #+#    #+#             */
/*   Updated: 2024/01/26 13:17:20 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
@brief:
Checker functions for map. Receives the map as a string
returns -1 in case of any error in the map

- Assumes that checks on loaded values (01EPC) have already being done;
- Assumes that *str is longer than 4 elements
	-> Checks for ground and less than 2x2 maps done in advance
*/

int	check_input(char *str)  // Remove free ed exit qui per farne uno con return (0);
{
	int	row_len;
	int	i;
	int	count;

	if (ft_strlen(str) < 4)
		return (0);
	row_len = 0;
	i = -1;
	count = 0;
	printf("I am passing the map check?");
	while (str[++i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'E' && 
				str[i] != 'P' && str[i] != 'C' && str[i] != '\n')
			return (0);
		if (str[i] == '\n')
		{
			if (row_len == 0)
				row_len = i; // if it is the first line set the size
			else if (row_len != count)
				return (0);
			count = 0; // Reset the counter if a new line character is hit
		}
		else
			count++;
	}
	printf("Yes!\n");
	return (1); // Return the length of the rows
}

int	is_edge_walled(char **map, t_pos size)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (i < size.x)
	{
		if (map[0][i] != '1' || map[size.y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < size.y)	
	{
		if (map[i][0] != '1' || map[i][size.x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
