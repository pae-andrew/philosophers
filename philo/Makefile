# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 14:11:20 by gcredibl          #+#    #+#              #
#    Updated: 2021/07/24 15:27:26 by gcredibl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = gcc -Wall -Wextra -Werror

OBJ_DIR = obj/

CFILES = main.c \
		create.c \
		eat.c \
		utils.c

CFIND = $(CFILES:%=%)

OFILES = $(CFILES:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OFILES))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
				$(FLAGS) -o $(NAME) $(addprefix $(OBJ_DIR), $(OFILES))

$(OBJ): $(CFIND)
				@$(MAKE) $(OFILES)
$(OFILES):
			@echo Compiled: $(@:obj/%=%)
			@$(FLAGS)  -c -o $(OBJ_DIR)$@ $(@:%.o=%.c)
clean:
				/bin/rm -rf $(OBJ_DIR)

fclean:			clean
				/bin/rm -f $(NAME)

re: 			fclean all

.PHONY:			clean fclean re