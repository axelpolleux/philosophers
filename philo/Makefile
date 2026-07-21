CC				:=	cc
CFLAGS			:=	-Wall -Werror -Wextra -pthread -g
NAME			:=	philo

SRCS			:=	main.c		\
					numbers.c	\
					philo.c		\
					parser.c

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