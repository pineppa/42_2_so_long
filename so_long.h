/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:21:01 by jsala             #+#    #+#             */
/*   Updated: 2024/01/23 22:32:56 by jsala            ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512

# endif

# define WALL_IMG "./img/wall.xpm"
# define EMPTY_IMG "./img/empty.xpm"
# define COLLECTIBLE_IMG "./img/collectible.xpm"
# define PLAYER_IMG "./img/player.xpm"
# define EXIT_IMG "./img/exit.xpm"
# define PATROL_IMG "./img/patrol.xpm"

# define ESC
# define DOWN
# define UP
# define LEFT
# define RIGHT
# define W
# define A
# define S
# define D
# define SPACE

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
	t_sprite		*spr_c; //List of collectibles
	t_sprite		*spr_p; //List of player sprites
	t_sprite		*spr_e; //List of exits
} t_map;

typedef struct s_sprite
{
	t_pos			pos;
	char			sprite_char;
	unsigned int	sprite_id;
	//unsigned int	life;
	//unsigned int	attack;
	//unsigned int	defense;
} t_sprite;

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

// Libft functions
void	ft_putstr_fd(char *message, int fd);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);

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

char	**read_mapfile(int fd);
t_pos	*get_map_size(char **map);
int 	check_input(char *str);
int		load_map(char *map_file, t_map *map);
char	**read_mapfile(int fd);
int		is_edge_walled(char **map, t_pos *size);

#endif