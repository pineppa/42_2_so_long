SRCS = 

OBJ_SRCS = 

INCLUDE_MLX = -I/usr/include -Imlx_linux -03

NAME = 

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE_MLX) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


