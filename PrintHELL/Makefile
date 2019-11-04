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

NAME = libftprintf.a

SRCS = *.c

INCLUDES=./

OBJ = *.o

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS) $<
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all