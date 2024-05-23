NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := src/*.c
GETNEXTLINE := get_next_line/*c
LIBRARY := -lmlx -lXext -lX11 -L./minilibx
PRINTF_LIB := ft_printf/libftprintf.a
PRINTF := ft_printf/*c 
MINILIBX := minilibx/

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

all:
	make -C $(MINILIBX)
	make -C ft_printf
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINTF_LIB) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
	make clean -C $(MINILIBX)
	make fclean -C ft_printf
	rm -rf $(NAME)

re: fclean all
