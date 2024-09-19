NAME := so_long

CC := cc

FLAGS := -Wall -Wextra -Werror

HEADER := so_long.h

MLXI := ./MLX42

INCLUDES := -I/MLX42

MLX_FLAGS := ./MLX42/build/libmlx42.a -L/usr/lib/x11 -lXext -lX11 -ldl -lglfw

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

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $^ $(MLX_FLAGS) -o $@

libmlx:
	@cmake $(MLXI) -B $(MLXI)/build && make -C $(MLXI)/build -j4

# sup is a rule to create a file, which when compiled correctly
# it will prevent display of leaks related to the Codam MLX42:
sup:
	@echo > suppression_file.sup "{\n\t<MLX_CODAM>\n\tMemcheck:Leak\n\tmatch-leak-kinds: reachable\n\t...\n\tfun:_dl_catch_exception\n\t...\n}\n{\n\t<MLX_CODAM>\n\tMemcheck:Leak\n\tmatch-leak-kinds: reachable\n\t...\n\tfun:mlx_init\n\t...\n}\n{\n\t<MLX_CODAM>\n\tMemcheck:Leak\n\tmatch-leak-kinds: reachable\n\t...\n\tfun:XrmGetStringDatabase\n\t...\n}\n{\n\t<MLX_CODAM>\n\tMemcheck:Leak\n\tmatch-leak-kinds: reachable\n\t...\n\tfun:_XrmInitParseInfo\n\t...\n}\n{\n\t<MLX_CODAM>\n\tMemcheck:Leak\n\tmatch-leak-kinds: reachable\n\t...\n\tfun:__tls_get_addr\n\t...\n}\n{\n\t<MLX_CODAM>\n\tMemcheck:Leak\n\tmatch-leak-kinds: reachable\n\t...\n\tfun:__pthread_once_slow\n\t...\n}"

cleansup:
	rm -f "suppression_file.sup"

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean:
	rm -f $(OFILES) $(NAME)

re: fclean all

.PHONY: all clean fclean re sup
