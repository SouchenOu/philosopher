# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 11:17:18 by souchen           #+#    #+#              #
#    Updated: 2022/05/22 18:19:50 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

FILES =  initialisation.c main.c die.c philo.c util.c args.c join_and_free.c

OBJ_FILES = $(FILES:.c=.o)

HEADER = header/philo.h

FLAGS = -Wall -Wextra - Werror

all : $(NAME)

$(NAME) : $(OBJ_FILES) $(HEADER)
	$(CC) $(OBJ_FILES) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ_FILES)
	

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
