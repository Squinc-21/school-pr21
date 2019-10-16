 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsedgeki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:35:23 by lsedgeki          #+#    #+#              #
#    Updated: 2019/09/07 16:40:59 by lsedgeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = *.c

INCLUDES=./

OBJ = *.o

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

$(OBJ):
	@gcc -Wall -Wextra -Werror -c $(SRCS) -I $(INCLUDES)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all