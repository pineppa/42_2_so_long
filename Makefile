SRCS = map_checker.c map_loader.c so_long.c gui_handler.c input_handler.c utils.c movements.c

INCLUDE = -I. -Iminilibx_linux

OBJ_SRCS = $(SRCS:.c=.o)

MLX_FLAGS = -L ./libft -L ./minilibx_linux -lmlx -lXext -lX11 -lm -lbsd -lz

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

NAME = so_long

CC = gcc #-03
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $(LIBFT) $(INCLUDE) $(MLX_INCLUDE) $< -o $(<:.c=.o)

$(NAME) : $(LIBFT) $(OBJ_SRCS)
	$(CC) $(OBJ_SRCS) $(MLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)

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
