/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:49:01 by jsala             #+#    #+#             */
/*   Updated: 2024/01/27 12:02:52 by jsala            ###   ########.fr       */
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
