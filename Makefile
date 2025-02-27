SRCS = map_checker.c map_checker_utils.c map_path_check.c map_loader.c so_long.c gui_handler.c render.c input_handler.c utils.c moves.c moves_utils.c exit.c
HEADER = so_long.h
SRCS_DEBUG = ${SRCS} test_utils.c

INCLUDE = -I. -I./minilibx_linux -I./libft

OBJ_SRCS = $(SRCS:.c=.o)
OBJ_SRCS_DEBUG = $(SRCS_DEBUG:.c=.o)

MLX_FLAGS = ./minilibx_linux/libmlx_Linux.a -lXext -lX11

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

NAME = so_long

CC = gcc# -03
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all : $(NAME) $(HEADER) Makefile

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ_SRCS) $(LIBFT) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJ_SRCS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT) : 
	make -C ./libft
	make -C ./libft clean

debug : $(OBJ_SRCS_DEBUG) $(LIBFT) $(HEADER) Makefile
	$(CC) -g -fsanitize=address $(CFLAGS) $(OBJ_SRCS_DEBUG) $(LIBFT) $(MLX_FLAGS) -o $(NAME)_debug

clean :
	$(RM) $(OBJ_SRCS_DEBUG)
	make -C $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all fclean clean re
