/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:20:39 by jsala             #+#    #+#             */
/*   Updated: 2024/01/22 16:22:53 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #include <mlx.h>
#include <stdio.h>

/*
int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
*/

void    print_map(char **map)
{
    int i = 0;
	
    while (map[i])
        printf("%s\n", map[i++]);
}

void	throw_error(char *message)
{
	perror("Error");
	ft_putstr_fd(message, 2);
	write(2, "\n", 1);
}
/*
void	mlx_exit(void *mlx_ptr, void win_ptr)
{
	free_stuff;
	mlx_clear_window();
	mlx_destroy_window();
}

void	manage_gui(void)
{
	mlx_ptr = mlx_init(); //Sets up a connection to the X Server
	if (!mlx_ptr)
		return (1); //Shall it throw an error?
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "So long");
	if (!win_ptr)
		return (1); //Shall it throw an error and free mlx_ptr?
	mlx_key_hook(win_ptr, &ft_key, void);
	mlx_mouse_hook(win_ptr, &ft_mouse, void);
	mlx_expose_hook(win_ptr, &ft_expose, void);    
	mlx_loop(mlx_ptr); //Infinite loop (while(1) that waits for keyboard / mouse signals)
	mlx_exit(mlx_ptr, win_ptr);
}
*/
int	main(int argc, char **argv)
{
	//void	*mlx_ptr;
	//void	*win_ptr;
	t_map *map;

	if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) //Doesn't block fake names, should check the file extension and MIME file
	{
		write(1, "Correct input format: $>so_long *.ber.", 38);
		return (1);
	}
	map = malloc(sizeof(t_map));
	if (!map || !argv[1])
		return (1);
	if (!load_map(argv[1], map))
	{
		free(map);
		return (1);
	}
	return (0);
}

// Init image memory / space
// void	*img = mlx_new_image(mlx, 1920, 1080);
// is map a .ber file?
