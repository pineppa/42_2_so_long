/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:21:01 by jsala             #+#    #+#             */
/*   Updated: 2024/01/26 15:31:19 by jsala            ###   ########.fr       */
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

// # define WIN_W 1024
// # define WIN_H 720
# define IMG_W 64
# define IMG_H 64

# define WALL_IMG "./img/wall_blue_64x64.xpm"
# define GROUND_IMG "./img/empty_green_64x64.xpm"
# define COLLECTIBLE_IMG "./img/collectible.xpm"
# define PLAYER_IMG "./img/player_green_64x64_0.xpm"
# define EXIT_IMG "./img/exit_green_64x64.xpm"
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

typedef struct s_anima 
{
	void    		*img;
	char			*addr;
	int				w; // width of the image
	int				h; // height of the image
	int				bpp;
	int				line_length;
	int				endian;
	struct s_anima	*next; // Points to the next image in the animation
} t_anima;

typedef struct s_obj
{
	t_pos			pos;
	t_anima			*anima;
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
	unsigned int	n_collecs;
	unsigned int	n_exits;
	t_obj			*collecs; // List of collectibles
	t_obj			*exits; // List of exits
	t_obj			*p1; // Player 1 object
	t_obj			*wall; // Single item stored (Later could turn in different walls);
	t_obj			*ground; // Single item stored (Later could turn in different grounds);
} t_map;

typedef struct s_data
{
	void	*mlx_conn;
	void	*window;
	t_map	*map;
	int		end;
} t_data;

// Utils
void	print_map(char **map); // Used for debugging only
void	throw_error(char *message);

// Game functions
// Initialisation

int		init_map(t_data *game, char *map_file);
int		init_objects(void *mlx_conn, t_map *map);
t_anima	*load_img(void *mlx_conn, char *map_file);
t_obj	*load_obj(void *mlx, char *img_file, char obj_char);
int		init_game_gui(t_data *game);

// Input Handler
int		init_keys(t_data *game);
int		handle_key_input(int keysim, t_map *map);

// Map loader

void	free_matrix(char **matrix);
t_pos	get_map_size(char **map);
char	**read_mapfile(int fd);
int		load_map(char *file, t_map *map);

// Map checker

int		check_input(char *str);
int		is_edge_walled(char **map, t_pos size);

// Moves

void	move(int keysim, t_obj *obj, t_map *map);
char	**move_up(char **map, t_pos map_size, t_obj *obj);
char	**move_down(char **map, t_pos map_size, t_obj *obj);
char	**move_left(char **map, t_pos map_size, t_obj *obj);
char	**move_right(char **map, t_pos map_size, t_obj *obj);

// Rendering

int		ft_render(t_data *game);
void	draw_game_gui(t_data *game, t_map *map);

// Drawings

int 	draw_item(t_data *game, t_obj *item, t_pos pos);

// Moves_utils

int		is_move_inbound(t_pos map_size, int x, int y);
int		is_move_wall(char **map, int x, int y);
int		is_player_exit(char **map, int x, int y);
int		is_player_collect(char **map, int x, int y);
int		is_player_patrol(char **map, int x, int y);

// Other functions

// void	attack(int keysim, t_obj obj, t_map *map);

#endif