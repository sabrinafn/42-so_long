NAME := so_long

CC := cc

FLAGS := -Wall -Wextra -Werror

HEADER := so_long.h

INCLUDES := -I/usr/include -Imlx
MLX_FLAGS := -Lmlx_linux -lmlx_Linux -L/usr/lib/x11 -Imlx_linux -lXext -lX11

CFILES := main.c

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
