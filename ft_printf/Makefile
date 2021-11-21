# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 15:42:40 by espyromi          #+#    #+#              #
#    Updated: 2021/09/01 19:19:34 by espyromi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c functions_1.c functions_2.c functions_3.c functions_4.c

OBJS = ${SRCS:.c=.o}

CC 		= gcc

RM 		= rm -fr

CFLAGS = -Wall -Wextra -Werror

.c.o:

		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all