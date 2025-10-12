NAME = cube

SRC_DIR = src
SRCS = main.c player.c map.c move.c movement_utils.c drawing_utils.c raycast.c textures.c raycast_utils.c mini_map.c
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes/mlx -g3
MLX = includes/mlx/libmlx_Linux.a
MLX_FLAGS = -Lincludes/mlx -lmlx -lXext -lX11 -lm -lz

$(NAME): $(OBJS) $(MLX)
	$(CC) $(OBJS) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
