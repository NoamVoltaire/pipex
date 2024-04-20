NAME = pipex
CC = gcc
CFLAGS = -Iinclude -Ift_printf_fd
DEPS = include/pipex.h ft_printf_fd/ft_printf_fd.h
OBJ = srcs/init_pipex.o srcs/main.o srcs/utils.o srcs/free.o str_utils/ft_split.o str_utils/ft_strchr.o str_utils/ft_strjoin.o str_utils/ft_strlen.o str_utils/ft_strncmp.o ft_printf_fd/auxilary_fun.o ft_printf_fd/ft_printf_fd.o ft_printf_fd/ft_putnbr_base.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean, fclean, re

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all