NAME    := run
CC      := cc -g

# we compile without flags while we doing the project, needs to be added later
CFLAGS  := -Wall -Wextra -Werror

INCLUDES := ./includes/header.h

SRCS := ./parse/ft_split.c \
		./parse/parser.c \
		./parse/utils.c \
		./parse/ft_split_validation.c \
		./parse/validation.c \
		./mains/main.c \
		./moves/moves_a.c \
		./moves/moves_b.c \


OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES) Makefile
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean re all
