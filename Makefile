NAME = so_long

SRC_DIR = src

OBJS_DIR = objs

LIBMLX = MLX42

HEADERS := -I ./include -I $(LIBMLX)/include -I libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

LIBS := $(LIBMLX)/build/libmlx42.a libft/libft.a  -lglfw -pthread -lm

SRCS = main.c find_player.c flood_fill.c map_shape.c map_validation.c pec_check.c \
	   texture_load.c wall_check.c find_last.c window_create.c title_check.c \
	   player_movement.c player_hook.c collected.c exit.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: libmlx $(NAME)

libmlx: MLX42/.git
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

MLX42/.git:
	git submodule update --init MLX42

libft/libft.a:
	@make -C libft

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) libft/libft.a $(LIBMLX)/build/libmlx42.a
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(LIBMLX)/build
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all re fclean clean libmlx libft/libft.a
