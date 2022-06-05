NAME = philo

SRCS = main.c help.c dine.c init.c time.c end.c

INCLUDE = philosopher.h

OBJS = ${SRCS:.c=.o}

CC			= gcc

RM			= rm -fr

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		@${CC} ${CFLAGS} -c -g -pthread $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS} ${INCLUDE}
		@${CC} -pthread -o ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		@${RM} ${NAME}${NAME_BONUS}

re:		fclean all
		