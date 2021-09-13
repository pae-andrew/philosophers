
SRCS	= main.c

SRCS	+= error_manager.c init.c utils.c launcher.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CLANG	= gcc

FLAGS	= -Wall -Wextra -Werror

INCLUDE	= -pthread

HEADER	= philo.h


all:	$(NAME)

$(NAME): $(OBJS)
	$(CLANG) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CLANG) $(FLAGS) -c $<  -o $(<:.c=.o) -I /

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY:	clean fclean re 