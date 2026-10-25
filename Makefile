NAME    := push_swap
CC      := cc -g
BONUS   := checker

# we compile without flags while we doing the project, needs to be added later
CFLAGS  := -Wall -Wextra -Werror

INCLUDES := ./includes/header.h

SRCS := ./parse/ft_split.c \
		./parse/parser.c \
		./parse/ft_split_utils.c \
		./parse/ft_split_validation.c \
		./parse/validation.c \
		./parse/ft_definitions.c \
		./parse/disorder.c \
		bench.c \
		./mains/main.c \
		./moves/moves_a.c \
		./moves/moves_b.c \
		./moves/moves_ab.c \
		./moves/moves_utils.c \
		./sort/mini_sort.c \
		./sort/sort_utils.c \
		./sort/selection_sort.c \
		./sort/sort_complex.c \
		./sort/sort_medium.c \
		./sort/sort_medium_utils.c \
		sort_dispatch.c \

SRCS_BONUS := ./parse/ft_split.c \
		./parse/parser.c \
		./parse/ft_split_utils.c \
		./parse/ft_split_validation.c \
		./parse/validation.c \
		./parse/ft_definitions.c \
		./mains/bonus_main.c \
		./moves/moves_a.c \
		./moves/moves_b.c \
		./moves/moves_ab.c \
		./moves/moves_utils.c \
		./sort/sort_utils.c \
		./bonus/get_next_line.c \
		./bonus/get_next_line_utils.c \

OBJS := $(SRCS:.c=.o)
OBJS_BONUS := $(SRCS_BONUS:.c=.o)



all : $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)

$(BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(BONUS)

%.o: %.c $(INCLUDES) Makefile
	$(CC) -c $< -o $@


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean re all
