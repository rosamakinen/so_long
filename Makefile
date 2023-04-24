# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 13:30:50 by rmakinen          #+#    #+#              #
#    Updated: 2023/04/24 11:45:34 by rmakinen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FILES = test map_check
SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@cd libft && $(MAKE)
	@cc $(FLAGS) -c $(SRC)
	@cc $(FLAGS) $(OBJ) libft/libft.a -L /usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@cd libft && make clean
	@rm -f $(OBJ)

fclean: clean
	@cd libft && make fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re