NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux

MLX_DIR = minilibx-linux
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a
LDLIBS = -lX11 -lXext -lm

SRC = src/main.c src/game_control.c src/input_control.c src/map_parser.c \
	src/map_validator.c src/map_validator_helper.c src/render_utils.c \
	src/str_arr_utils.c src/utils.c
OBJ = $(SRC:.c=.o)

all: $(MLX_LIB) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) $(LDLIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean || true
	$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean || true
	-rm -f $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re