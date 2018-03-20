#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vliubko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/09 20:59:37 by vliubko           #+#    #+#              #
#    Updated: 2017/08/10 12:46:05 by vliubko          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FILES = ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_strdup.c ft_atoi.c \
ft_strcpy.c ft_strncpy.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
ft_tolower.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_memalloc.c ft_memdel.c ft_putendl.c ft_strnew.c ft_strdel.c \
ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_swap.c \
ft_int_sort.c ft_isspace.c ft_strrev.c ft_sqrt.c ft_count_elems.c \
ft_free_2d_array.c get_next_line.c

SRC		= $(addprefix src/, $(FILES))
OBJ		= $(SRC:.c=.o)
HEADER	= includes/libft.h
INC		= -I includes

FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(OBJ): %.o : %.c $(HEADER)
	@gcc $(FLAGS) -c $(INC) $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mLibft \033[1;32mLibft \033[1;0m\033[32m created.\033[0m"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mLibrary \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all
