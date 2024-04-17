# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noam <noam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 23:32:25 by noam              #+#    #+#              #
#    Updated: 2023/11/27 00:56:24 by noam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c \
		ft_putnbr_base.c \
		auxilary_fun.c 
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	ar rcs $@ $^
	ranlib $@

a.out : $(OBJS)
	 $(CC) $(FLAGS) -o $@ $^
	 
all : $(NAME)

.PHONY: clean, fclean, re
clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)
	rm -f a.out

re : fclean all