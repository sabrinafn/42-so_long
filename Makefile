NAME := so_long

CC := cc

FLAGS := -Wall -Wextra -Werror

HEADER := so_long.h

CFILES := main.c

OFILES := $(CFILES:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $^ -o $@

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
