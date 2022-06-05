NAME			=	minishell
CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror -g
RM				=	rm -rf
INCLUDE			=	libft/libft.h minishell.h

SRCS_LIST		=	main.c builtin.c errors.c check.c execute.c split_input.c\
					create.c signal.c redirect.c get_next_line.c \
					builtin_utils.c get_next_line_utils.c split_input_utils.c\
					redirect_utils.c
SRCS_DIR		=	src/
SRCS			=	${addprefix ${SRCS_DIR}, ${SRCS}}

OBJS_LIST		=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS_DIR		=	obj/
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST)) $(GNL:.c=.o)

LIBFT			=	$(LIBFT_DIR)libft.a
LIBFT_DIR		=	libft/

UNAME			=	$(shell uname)

ifeq ($(UNAME), Darwin)
	LDFLAGS  		=   -L/usr/local/opt/readline/lib
	CPPFLAGS 		=   -I/usr/local/opt/readline/include
else
	LDFLAGS  		=   
	CPPFLAGS 		=   
endif

RLFLAG			=	-lreadline

GREEN			=	\033[0;32m
RED				=	\033[0;31m
RESET			=	\033[0m

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS_DIR) $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) $(CPPFLAGS) $(LDFLAGS) $(RLFLAG) $(LIBFT) -o $(NAME)

$(OBJS_DIR):
				@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c 
				@$(CC) $(CFLAGS) $(CPPFLAGS) -c -I$(SRCS_DIR) $< -o $@

$(LIBFT):
				@echo "$(GREEN)Compiling $(LIBFT)...$(RESET)"
				@$(MAKE) -sC $(LIBFT_DIR)

clean:
			@$(MAKE) -sC $(LIBFT_DIR) clean
			@$(RM) $(OBJS_DIR)
			@echo "$(RED)cleaned$(RESET)"

fclean:		clean
			@$(MAKE) -sC $(LIBFT_DIR) fclean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
