/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:21:01 by jsala             #+#    #+#             */
/*   Updated: 2024/01/22 16:16:34 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
// # include <mlx.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512

# endif

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
} t_pos;

typedef struct s_map
{
	char			**map_content;
	t_pos			map_size;
	unsigned int	c;
	unsigned int	players;
	unsigned int	exits;
	t_pos			pos_c;
	t_pos			pos_p;
	t_pos			pos_e; 
} t_map;

void	ft_putstr_fd(char *message, int fd);
char	**read_mapfile(int fd);
t_pos	get_map_size(char **map);
void    print_map(char **map);
void    throw_error(char *message);
int 	check_input(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char *str);
int		load_map(char *file, t_map *map);
char	**ft_split(char const *s, char c);
char	**read_mapfile(int fd);
int		is_edge_walled(char **map, t_pos size);
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif