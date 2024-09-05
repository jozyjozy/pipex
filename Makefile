# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 10:47:05 by jlarue            #+#    #+#              #
#    Updated: 2023/03/16 14:32:23 by jlarue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc -Wall -Werror -Wextra -g

RM = rm -f

SRC = ./mandatory/main.c \
	  ./mandatory/ft_utils.c \
	  ./mandatory/ft_split.c \
	  ./mandatory/ft_strlen.c \
	  ./mandatory/ft_join.c	\
	  ./mandatory/ft_putstrfd.c \
	  ./mandatory/ft_utils2.c \

BONUS_SRC = ./bonus/mainbonus.c \
	  		./bonus/ft_utilsbonus.c \
	  		./bonus/ft_splitbonus.c \
	  		./bonus/ft_strlenbonus.c \
	  		./bonus/ft_joinbonus.c	\
			./bonus/ft_putstrfdbonus.c \
	  		./bonus/ft_utils2bonus.c

OBJ = ./mandatory/main.o ./mandatory/ft_utils.o ./mandatory/ft_split.o ./mandatory/ft_strlen.o ./mandatory/ft_join.o ./mandatory/ft_putstrfd.o ./mandatory/ft_utils2.o

BONUS_OBJ = ./bonus/mainbonus.o ./bonus/ft_utilsbonus.o ./bonus/ft_splitbonus.o ./bonus/ft_strlenbonus.o ./bonus/ft_joinbonus.o ./bonus/ft_putstrfdbonus.o ./bonus/ft_utils2bonus.o


.c.o:
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean:    clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
