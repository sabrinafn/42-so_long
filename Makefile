NAME := so_long

CC := cc

FLAGS := -Wall -Wextra -Werror

HEADER := .

MLX42 := ./MLX42/build/libmlx42.a

MLXI := ./MLX42

#INCLUDES := -I/MLX42

#MLX_FLAGS := ./MLX42/build/libmlx42.a -L/usr/lib/x11 -lXext -lX11 -ldl -lglfw
MLX_FLAGS := -pthread -lm -ldl -lglfw

CFILES := src/main.c \
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/ft_utils.c \
	src/ft_check_args.c \
	src/ft_args_checklist.c \
	src/ft_init_map.c \
	src/ft_check_valid_path.c \
	src/ft_init_window.c \
	src/ft_init_window_utils.c \
	src/ft_put_images.c 

OFILES := $(CFILES:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -I$(HEADER) -I$(MLXI) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $^ $(MLX42) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

libmlx:
	@cmake $(MLXI) -B $(MLXI)/build
	$(MAKE) -C $(MLXI)/build -j4

mlxclean:
	rm -rf $(MLXI)/build/

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re libmlx mlxclean
