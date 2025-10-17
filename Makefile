NAME = tic_tac_toe

SRCS = main.c \
	Functions/tic-tac-toe.c \
	Functions/string_modif.c \
	Functions/user_modif.c \
	Functions/verification.c \
	Functions/bot.c

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all