/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:21:01 by jsala             #+#    #+#             */
/*   Updated: 2024/01/24 18:20:29 by jsala            ###   ########.fr       */
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
# include <mlx.h>
# include <stdio.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512

# endif

# define WALL_IMG "./img/wall.xpm"
# define EMPTY_IMG "./img/empty.xpm"
# define COLLECTIBLE_IMG "./img/collectible.xpm"
# define PLAYER_IMG "./img/player.xpm"
# define EXIT_IMG "./img/exit.xpm"
# define PATROL_IMG "./img/patrol.xpm"

# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define W 119
# define A 97
# define S 112
# define D 100
# define SPACE 32
# define ENTER 65293

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
} t_pos;

typedef struct s_sprite
{
	t_pos			pos;
	char			spr_char;
	unsigned int	spr_id;
	//unsigned int	life;
	//unsigned int	attack;
	//unsigned int	defense;
} t_sprite;

typedef struct s_map
{
	char			**map_content;
	t_pos			map_size;
	unsigned int	c;
	unsigned int	players;
	unsigned int	exits;
	t_sprite		*spr_c; //List of collectibles
	t_sprite		*spr_p; //List of player sprites
	t_sprite		*spr_e; //List of exits
} t_map;

typedef struct s_image 
{
	void    *img;
	char	*addr;
	int		width;
	int		length;
	int		bpp;
	int		line_length;
	int		endian;
} t_image;

typedef struct s_data
{
	void	*mlx_conn;
	void	*window;
	t_map	*map;
	t_image *img_wall;
	t_image	*img_empty;
	t_image	*img_collectible;
	t_image	*img_player;
	t_image	*img_exit;
	t_image	*img_patrol;
} t_data;

/*
// Libft functions
void	ft_putstr_fd(char *message, int fd);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
*/

// Utils
void    print_map(char **map); // Used for debugging only
void    throw_error(char *message);

// Game functions
// Initialisation

int		init_map(t_data *game, char *map_file);
int		init_images(t_data *game);
t_image	*load_img(t_data *game, char *map_file);
void	draw_game_gui(t_data *game);
int		init_game_gui(t_data *game);

// Input Handler
int		init_keys(t_data *game);
int		handle_key_input(int keysim, t_data *game);

// Map loader

void	free_matrix(char **matrix);
t_pos	get_map_size(char **map);
char	**read_mapfile(int fd);
int		load_map(char *file, t_map *map);

// Map checker

int 	check_input(char *str);
int		is_edge_walled(char **map, t_pos size);

// Moves

int		is_valid_move(char **map, char spr_char, int x, int y);
void	move(int keysim, t_sprite spr, char **map);

// Moves_utils

int is_move_inbound(char **map, int x, int y);
int	is_move_wall(char **map, int x, int y);

// Other functions

t_pos	get_map_size(char **map);

#endif