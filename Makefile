NAME		:= Game
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX		:= ./MLX42
FTPRINTF	:= ./ft_printf/libftprintf.a

HEADERS	:= -I ./include -I $(LIBMLX)/include/MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L"/Users/$(USER)/.brew/opt/glfw/lib/"
SRCS	:= main.c paint_image.c math.c keyhooks.c input.c utils.c free_stuff.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@git submodule init MLX42
	@git submodule update MLX42
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) $(FTPRINTF)
	@$(CC) $(OBJS) $(FTPRINTF) $(LIBS) $(HEADERS) -o $(NAME)

$(FTPRINTF):
	@git submodule init ft_printf
	@git submodule update ft_printf
	@cd ft_printf && make && make clean


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
