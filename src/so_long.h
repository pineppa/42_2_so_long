/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:21:01 by jsala             #+#    #+#             */
/*   Updated: 2024/03/14 17:54:36 by jsala            ###   ########.fr       */
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
# include <stdio.h>
# include "libft/libft.h"
# include <mlx.h>
# include "mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512

# endif

// Signals
# define ON_DESTROY 17

# define IMG_W 64
# define IMG_H 64
# define MAX_MAP_W 15
# define MAX_MAP_H 12
# define TEXT_COLOR 0x00000000

# define FRAMES_ANIMA 6
# define WALL_IMG "./img/wall_blue_64x64.xpm"
# define GROUND_IMG "./img/empty_green_64x64.xpm"
# define COLLECTIBLE_IMG "./img/collectible_green.xpm"
# define PLAYER_IMG "./img/player_green_64x64_0.xpm"
# define EXIT_IMG "./img/exit_green_64x64.xpm"
# define PATROL_IMG "./img/patrol_green_64x64_0.xpm"

# define ESC 53
# define LEFT 123
# define UP 126
# define RIGHT 124
# define DOWN 125
# define W 13
# define A 0
# define S 1
# define D 2
# define SPACE 32
# define ENTER 36

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_anima
{
	void			*img;
	int				w;
	int				h;
	int				bpp;
	int				line_length;
	int				endian;
}	t_anima;

typedef struct s_obj
{
	t_pos			pos;
	t_anima			*anima;
	char			obj_char;
	unsigned int	obj_id;
}	t_obj;

typedef struct s_map
{
	char			**map_content;
	t_pos			map_size;
	unsigned int	n_collecs;
	unsigned int	n_exits;
	t_obj			*collecs;
	t_obj			*exits;
	t_obj			*p1;
	t_obj			*wall;
	t_obj			*ground;
	int				moves;
}	t_map;

typedef struct s_data
{
	void	*mlx_conn;
	void	*window;
	t_map	*map;

}	t_data;

// Utils
void	print_map(char **map);
void	throw_error(char *message);
int		ft_check_file_extension(char *str);
char	*get_file_path(char *base_file, int frame);

// Game functions
// Initialisation

int		init_map(t_data *game, char *map_file);
int		init_objects(void *mlx_conn, t_map *map);
int		init_nr_objs(t_map *map);
t_anima	*load_img(void *mlx_conn, char *map_file);
t_obj	*load_obj(void *mlx, char *img_file, char obj_char);
int		init_game_gui(t_data *game);

// Input Handler
int		init_keys(t_data *game);
int		handle_key_input(int keysim, t_data *game);

// Map loader

t_pos	get_map_size(char **map);
char	**read_mapfile(int fd);
int		load_map(char *file, t_map *map);

// Map checker

int		check_input(char *str);
int		is_edge_walled(char **map, t_pos size);

// Map path checker

int 	check_valid_path(t_map *map);
char 	**copy_map(t_pos size, char **map);

// Moves

t_obj	*update_obj_pos(t_map *map, t_obj *obj, t_pos new_pos);
int		move_action(t_map *map, t_obj *obj, t_pos new_pos);
int		move(int keysim, t_obj *obj, t_map *map);

// Rendering

int		ft_render(t_data *game);
void	draw_game_map(t_data *game, t_map *map);

// Drawings

int		draw_item(t_data *game, t_obj *item, t_pos pos);

// Moves_utils

//int		is_move_valid(t_map *map, t_pos map_size, t_obj *obj, t_pos new_pos);
//int		is_move_inbound(t_pos map_size, int x, int y);
//int		is_move_wall(char **map, int x, int y);
int		player_exit(t_map *map);
int		player_collect(t_map *map);
int		player_patrol(void);

// Free allocations

int		game_exit(t_data *game);
void	free_matrix(char **matrix);
void	free_anima_list(void *mlx, t_anima **anima);
void	free_object(void *mlx, t_obj *obj);
void	free_map(t_data *game);

// Other functions
void	check_malloc(char *str, char *buff);

// void	attack(int keysim, t_obj obj, t_map *map);

#endif
