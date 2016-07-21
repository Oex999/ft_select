# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/11 08:42:28 by oexall            #+#    #+#              #
#    Updated: 2016/07/14 08:23:22 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_select

CC= gcc -o
CFLAGS= -Wall -Werror -Wextra
LIBFT= -L ./libft -lft

SP= ./src/
SRC= $(SP)ft_select.c \
	 $(SP)ft_select_list.c \
	 $(SP)ft_misc_select.c \
	 $(SP)ft_print_select.c \
	 $(SP)ft_term.c \
	 $(SP)ft_keyhook.c \
	 $(SP)ft_select_move.c \
	 $(SP)ft_list_select.c \
	 $(SP)ft_del_line.c \
	 $(SP)ft_signal.c \
	 $(SP)ft_size.c

$(NAME):
	@clear
	@echo "Compiling"
	@make -C libft fclean
	@make -C libft
	@$(CC) $(NAME) $(SRC) $(CFLAGS) $(LIBFT) -ltermcap
	@echo "Done"

quick:
	@clear
	@$(CC) $(NAME) $(SRC) $(CFLAGS) $(LIBFT) -ltermcap
	@echo "Done"

all: $(NAME)

clean:
	rm $(NAME)

fclean: clean
	@make -C fclean

re: fclean all

me:
	echo ${USER} > author

norm:
	@clear
	norminette $(SRC) ./includes/ft_select.h
