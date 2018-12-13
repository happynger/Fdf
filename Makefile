# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 12:25:04 by otahirov          #+#    #+#              #
#    Updated: 2018/12/13 13:11:48 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
LIBFT = -L libft -lft

SRC = *.c
BIN = libft/*.o
INC = -I libft/includes -I minilibx_macos/

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = fdf

RM = rm -rf

all : $(NAME)

$(NAME) :
	@echo "Generating 42 lib."
	@make -C libft
	@echo "Done."
	@echo "Generating the $(NAME)"
	@$(CC) $(FLAGS) $(SRC) $(MINILIBX) $(LIBFT) $(INC) -o $@
	@echo "Done."

clean :
	@$(RM) $(BIN)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

git :
	@git add .
	@git commit -m "Automated Update $(shell date | head -c 19 | tail -c 15 && echo)"
	@git push
	@echo "The update was pushed to the github"
