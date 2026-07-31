CC				:=	cc
CFLAGS			:=	-Wall -Werror -Wextra -pthread -g -fsanitize=address
NAME			:=	philo

SRCS			:=	main.c		\
					utils.c		\
					philo.c		\
					thread.c	\
					parser.c	\
					mutex.c

OBJS			:=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	@printf "\n✔ BUILD COMPLETE\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "[CLEAN]"
	@rm -rf $(OBJS)

fclean:		clean
	@echo "[FCLEAN]"
	@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re