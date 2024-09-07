NAME := so_long

CC := cc

FLAGS := -Wall -Wextra -Werror

HEADER := so_long.h

INCLUDES := -I/usr/include -Imlx

MLX_FLAGS := -Lmlx -lmlx -L/usr/lib/x11 -lXext -lX11

CFILES := main.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_utils.c

OFILES := $(CFILES:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $^ -o $@ $(MLX_FLAGS)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
