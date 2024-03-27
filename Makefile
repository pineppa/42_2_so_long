SRCS_CORE = map_checker.c map_path_check.c map_loader.c so_long.c gui_handler.c render.c input_handler.c utils.c moves.c moves_utils.c exit.c
SRCS = ${addprefix src/, $(SRCS_CORE)}
SRCS_BONUS = ${addprefix src_bonus/, $(SRCS_CORE)}

HEADER_CORE = so_long.h
HEADER = ${addprefix src/, $(HEADER_CORE)}
HEADER_BONUS = ${addprefix src_bonus/, $(HEADER_CORE)}

INCLUDE = -I. -I./mlx -I./libft

OBJ_SRCS = $(SRCS:.c=.o)
OBJ_SRCS_BONUS = $(SRCS_BONUS:.c=.o)
DEPS = $(SRCS:.c=.d)
DEPS_BONUS = $(SRCS_BONUS:.c=.d)

MLX = ./mlx/libmlx.a
MLX_DIR = ./mlx
MLX_FLAGS = ./mlx/libmlx.a -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc# -03
CC_DEBUG = cc -g
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $(<:.c=.o)

$(NAME) : $(MLX) $(LIBFT) $(OBJ_SRCS) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJ_SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)

$(MLX) :
	make -C $(MLX_DIR)

$(LIBFT) :
	make -C $(LIBFT_DIR)

-include ${DEPS} ${DEPS_BONUS}

clean :
	$(RM) $(OBJ_SRCS) $(OBJ_SRCS_BONUS) ${DEPS} ${DEPS_BONUS}
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean : clean
	$(RM) $(NAME)
	make -C ${MLX_DIR} fclean
	make -C $(LIBFT_DIR) fclean

debug : $(MLX) $(LIBFT) $(OBJ_SRCS) $(HEADER) Makefile
	$(CC_DEBUG) $(CFLAGS) $(OBJ_SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)

bonus : $(MLX) $(LIBFT) $(OBJ_SRCS_BONUS) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJ_SRCS_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME_BONUS)

re : fclean all

.PHONY : all fclean clean re
