# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 18:46:49 by vliubko           #+#    #+#              #
#    Updated: 2018/03/20 15:39:47 by vliubko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I includes -I libft/includes
LDFLAGS		:= -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

LIBFT		:= libft/libft.a
HEADER		 = includes/fdf.h

FILES		:= main \
			draw_legend \
			draw_map \
			error_free \
			init_mlx \
			keys_hook \
			legend_helpers \
			line_bresenham \
			move \
			parser \
			rotate \
			zoom

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(SRC:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(OBJ): %.o: %.c $(HEADER)
	@echo "\033[38;5;226m"
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo ""
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "\033[31mBinary \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all