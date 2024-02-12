SRCS = map_checker.c map_path_check.c map_loader.c so_long.c gui_handler.c render.c input_handler.c utils.c moves.c moves_utils.c exit.c
HEADER = so_long.h

INCLUDE = -I. -I./mlx -I./libft

OBJ_SRCS = $(SRCS:.c=.o)

MLX = libmlx.a
MLX_DIR = ./mlx
#MLX_FLAGS = ./minilibx_linux/libmlx_Linux.a -lXext -lX11
MLX_FLAGS = ./mlx/libmlx.a -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

NAME = so_long

CC = gcc# -03
CC_DEBUG = gcc -g
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME) : $(MLX) $(LIBFT) $(OBJ_SRCS) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJ_SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)

$(MLX) :
	make -C $(MLX_DIR)

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	$(RM) $(OBJ_SRCS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

debug : $(MLX) $(LIBFT) $(OBJ_SRCS) $(HEADER) Makefile
	$(CC_DEBUG) $(CFLAGS) $(OBJ_SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)


re : fclean all

.PHONY : all fclean clean re
