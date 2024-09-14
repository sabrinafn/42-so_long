NAME := so_long

CC := cc

FLAGS := -Wall -Wextra -Werror

HEADER := so_long.h

MLXI := ./MLX42

INCLUDES := -I/MLX42

MLX_FLAGS := ./MLX42/build/libmlx42.a -L/usr/lib/x11 -lXext -lX11 -ldl -lglfw

CFILES := main.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_utils.c \
	ft_args_check.c \
	ft_args_checklist.c \
	ft_init_map.c \
	ft_valid_map_functions.c \
	ft_init_window.c \
	ft_put_images.c \
	ft_linked_list_manager.c

OFILES := $(CFILES:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $^ -o $@ $(MLX_FLAGS)

libmlx:
	@cmake $(MLXI) -B $(MLXI)/build && make -C $(MLXI)/build -j4

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
