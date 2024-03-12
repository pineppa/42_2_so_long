SRCS_CORE = map_checker.c map_path_check.c map_loader.c so_long.c gui_handler.c render.c input_handler.c utils.c moves.c moves_utils.c exit.c
SRCS = ${addprefix("src", SRCS_CORE)}
SRCS_BONUS = ${addprefix("src_bonus", SRCS_CORE)}

HEADER = so_long.h

INCLUDE = -I. -I./mlx -I./libft

OBJ_SRCS = $(SRCS:.c=.o)
OBJ_SRCS_BONUS = $(SRCS_BONUS:.c=.o)

MLX = libmlx.a
MLX_DIR = ./mlx
MLX_FLAGS = ./mlx/libmlx.a -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

NAME = so_long
NAME = so_long_bonus

CC = cc# -03
CC_DEBUG = cc -g
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

bonus : $(MLX) $(LIBFT) $(OBJ_SRCS_BONUS) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJ_SRCS_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME_BONUS)

re : fclean all

.PHONY : all fclean clean re
