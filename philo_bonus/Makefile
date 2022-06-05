# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 11:17:18 by souchen           #+#    #+#              #
#    Updated: 2022/05/30 14:46:40 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

FILES =  initialisation.c main.c die.c philo.c util.c args.c join_and_free.c philo_name.c

OBJ_FILES = $(FILES:.c=.o)

HEADER = header/philo_bonus.h

all : $(NAME)

$(NAME) : $(OBJ_FILES) $(HEADER)
	$(CC) $(OBJ_FILES) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ_FILES)
	

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
