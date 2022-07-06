NAME = cub3D

SRCS = src/main.c src/copy_map.c src/handle_keys.c src/exit_game.c src/init.c \
		src/draw/get_next_point.c src/draw/help_draw.c src/draw/ray_casting.c src/draw/utils.c src/draw/screen_draw.c src/draw/calc.c \
		src/map_check/map_check.c src/map_check/map_check_helper.c src/map_check/map_color_helper.c src/map_check/map_texture_helper.c src/map_check/map_check_handler.c

OBJS = ${SRCS:.c=.o}

LIBFT = ./libft

CC = gcc

RM = rm -fr

CFLAGS = -Wall -Wextra -Werror

EXT_LIB = libmlx.a

UNAME := $(shell uname)

all: ${EXT_LIB} libft.a ${NAME}

ifeq ($(UNAME), Linux)
MINILIBXF = ./minilibx
MINILIBX  = ${MINILIBXF}/libmlx.a

%.o: %.c
		${CC} ${CFLAGS} -I/usr/include -Imlx -O3 -c $< -o ${<:.c=.o}

$(NAME): $(SRCS)
			$(CC) $(SRCS) -lm -L $(LIBFT) -lft $(MINILIBX) -L /usr/include/X11/extensions/ -lXext -lX11 -o $(NAME)

endif

ifeq ($(UNAME), Darwin)
MINILIBXF = ./minilibx
MINILIBX  = ${MINILIBXF}/libmlx.a

%.o: %.c
		${CC} ${CFLAGS} -Imlxmac -c $< -o ${<:.c=.o}

$(NAME): $(SRCS)
	$(CC) $(SRCS) -L $(LIBFT) -lft $(MINILIBX) -L /usr/X11/lib -lXext -lX11 -o $(NAME)

endif

${EXT_LIB}:
	make -C ${MINILIBXF}

libft.a:
	make -C ${LIBFT}

archive:
	ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} a.out mlx.h

fclean: clean
		${RM} ${NAME} ${EXT_LIB}
		make -C ${LIBFT} fclean
		make -C ${MINILIBXF} clean

re:		fclean all