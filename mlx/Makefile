# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 13:30:50 by rmakinen          #+#    #+#              #
#    Updated: 2023/05/10 12:55:20 by rmakinen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FILES = so_long map_check map_check_2 path_check errors window_handle game
SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@cd libft && $(MAKE)
	@cd mlx && $(MAKE)
	@cc $(FLAGS) -c $(SRC)
	@cc $(FLAGS) $(OBJ) libft/libft.a mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@cd libft && make clean
	@cd mlx && make clean
	@rm -f $(OBJ)

fclean: clean
	@cd libft && make fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
