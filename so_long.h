/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:21:01 by jsala             #+#    #+#             */
/*   Updated: 2024/01/26 10:05:42 by jsala            ###   ########.fr       */
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

# define WIN_W 1024
# define WIN_H 720
# define IMG_W 64
# define IMG_H 64

# define WALL_IMG "./img/wall_blue_64x64.xpm"
# define EMPTY_IMG "./img/empty_green_64x64.xpm"
# define COLLECTIBLE_IMG "./img/collectible.xpm"
# define PLAYER_IMG "./img/player.xpm"
# define EXIT_IMG "./img/exit.xpm"
# define PATROL_IMG "./img/patrol.xpm"

# define ESC 65307
# define ESC_X 65340 // TO BE CHANGED!! SHOULD BE X OF WINDOW
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
	int	x;
	int	y;
} t_pos;

typedef struct s_obj
{
	t_pos			pos;
	char			obj_char;
	unsigned int	obj_id;
	//unsigned int	life;
	//unsigned int	attack;
	//unsigned int	defense;
} t_obj;

typedef struct s_map
{
	char			**map_content;
	t_pos			map_size;
	unsigned int	c;
	unsigned int	players;
	unsigned int	exits;
	t_obj			*obj_c; //List of collectibles
	t_obj			*obj_p; //List of player objites
	t_obj			*obj_e; //List of exits
} t_map;

typedef struct s_item 
{
	void    *img;
	char	*addr;
	int		w;
	int		h;
	int		x;
	int		y;
	int		bpp;
	int		line_length;
	int		endian;
} t_item;

typedef struct s_data
{
	void	*mlx_conn;
	void	*window;
	t_map	*map;
	t_item	*img_wall;
	t_item	*img_empty;
	t_item	*img_collectible;
	t_item	*img_player;
	t_item	*img_exit;
	t_item	*img_patrol;
	int		end;
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
void	print_map(char **map); // Used for debugging only
void	throw_error(char *message);

// Game functions
// Initialisation

int		init_map(t_data *game, char *map_file);
int		init_items(t_data *game);
t_item	*load_img(void *mlx_conn, char *map_file);
void	draw_game_gui(t_data *game, char **map);
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

int		check_input(char *str);
int		is_edge_walled(char **map, t_pos size);

// Moves

void	move(int keysim, t_obj obj, t_map *map);
int		move_up(char **map, t_pos map_size, t_obj obj);
int		move_down(char **map, t_pos map_size, t_obj obj);
int		move_left(char **map, t_pos map_size, t_obj obj);
int		move_right(char **map, t_pos map_size, t_obj obj);

// Drawings

int 	draw_static_item(t_data *game, t_item *item, int x, int y);
int 	draw_dyn_item(t_data *game, t_item *item, int x, int y);

// Moves_utils

int		is_move_inbound(t_pos map_size, int x, int y);
int		is_move_wall(char **map, int x, int y);
int		is_player_exit(char **map, int x, int y);
int		is_player_collect(char **map, int x, int y);
int		is_player_patrol(char **map, int x, int y);

// Other functions

t_pos	get_map_size(char **map);
// void	attack(int keysim, t_obj obj, t_map *map);

#endif