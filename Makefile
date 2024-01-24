SRCS = map_checker.c map_loader.c so_long.c gui_handler.c input_handler.c utils.c moves.c moves_utils.c
HEADER = so_long.h

INCLUDE = -I. -I./minilibx_linux -I./libft

OBJ_SRCS = $(SRCS:.c=.o)

MLX_FLAGS = ./minilibx_linux/libmlx_Linux.a -lXext -lX11

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

NAME = so_long

CC = gcc# -03
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ_SRCS) $(LIBFT) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJ_SRCS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT) : 
	make -C ./libft
	make -C ./libft clean

clean :
	$(RM) $(OBJ_SRCS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all fclean clean re
