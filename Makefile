# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 22:32:44 by flormich          #+#    #+#              #
#    Updated: 2021/07/22 23:14:59 by flormich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
DIR_LIB = libft
HEADER = $(DIR_LIB)/libft.h push_swap.h
SRC_LIB = $(DIR_LIB)/ft_memset.c $(DIR_LIB)/ft_bzero.c $(DIR_LIB)/ft_memcpy.c \
		$(DIR_LIB)/ft_memccpy.c $(DIR_LIB)/ft_memmove.c \
		$(DIR_LIB)/ft_memchr.c $(DIR_LIB)/ft_memcmp.c $(DIR_LIB)/ft_strlen.c \
		$(DIR_LIB)/ft_isalpha.c $(DIR_LIB)/ft_isdigit.c \
		$(DIR_LIB)/ft_isalnum.c $(DIR_LIB)/ft_isascii.c $(DIR_LIB)/ft_isprint.c \
		$(DIR_LIB)/ft_toupper.c $(DIR_LIB)/ft_tolower.c \
		$(DIR_LIB)/ft_strchr.c $(DIR_LIB)/ft_strrchr.c $(DIR_LIB)/ft_strncmp.c \
		$(DIR_LIB)/ft_strlcpy.c $(DIR_LIB)/ft_strlcat.c \
		$(DIR_LIB)/ft_strnstr.c $(DIR_LIB)/ft_atoi.c $(DIR_LIB)/ft_calloc.c \
		$(DIR_LIB)/ft_strdup.c $(DIR_LIB)/ft_substr.c \
		$(DIR_LIB)/ft_strjoin.c $(DIR_LIB)/ft_strtrim.c $(DIR_LIB)/ft_split.c \
		$(DIR_LIB)/ft_itoa.c $(DIR_LIB)/ft_itoa_unsigned_int.c \
		$(DIR_LIB)/ft_itohex.c \
		$(DIR_LIB)/ft_itoa_with_sign.c $(DIR_LIB)/ft_itoa_without_sign.c \
		$(DIR_LIB)/ft_strmapi.c $(DIR_LIB)/ft_putchar_fd.c $(DIR_LIB)/ft_putstr_fd.c \
		$(DIR_LIB)/ft_putendl_fd.c $(DIR_LIB)/ft_putnbr_fd.c
SRC = ft_push_swap.c ft_link_chunk.c ft_check_argv.c ft_print_chunk.c

OBJ = $(SRC:.c=.o)
OBJ_LIB = $(SRC_LIB:.c=.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJ) $(OBJ_LIB)
	make all -C ./$(DIR_LIB)
	gcc -g -o push_swap $(OBJ) $(OBJ_LIB)
	ar rcs $(NAME) $(OBJ) $(OBJ_LIB)

clean:
	make clean -C ./$(DIR_LIB)
	rm -f $(OBJ) main.o

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./$(DIR_LIB)

bonus: $(NAME)

re: fclean all

.PHONY: all clean fclean re
