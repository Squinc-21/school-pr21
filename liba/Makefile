# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: squinc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 17:42:50 by squinc            #+#    #+#              #
#    Updated: 2019/09/16 22:28:22 by squinc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = libft.h

SRC = ft_atoi.c    ft_isdigit.c     ft_memcmp.c       ft_putchar.c    ft_strclr.c \
    ft_striter.c  ft_strncat.c  ft_strrchr.c    ft_bzero.c    ft_isprint.c \
    ft_memcpy.c   ft_putnbr.c   ft_strcmp.c   ft_striteri.c ft_strncmp.c \
    ft_strsplit.c    ft_isalnum.c  ft_memalloc.c ft_memdel.c   ft_putstr.c \
    ft_strcpy.c   ft_strlcat.c  ft_strncpy.c  ft_strstr.c ft_isalpha.c \
    ft_memccpy.c  ft_memmove.c  ft_strcat.c   ft_strdel.c   ft_strlen.c \
    ft_strnew.c   ft_tolower.c    ft_isascii.c  ft_memchr.c   ft_memset.c \
    ft_strchr.c   ft_strdup.c   ft_strmap.c   ft_strnstr.c  ft_toupper.c \
    ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c \
    ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_putendl.c ft_lstmap.c \
	ft_lstadd.c ft_lstdel.c  ft_lstdelone.c ft_lstiter.c ft_strjoin.c \
	ft_strtrim.c ft_lstnew.c


OBJ = ft_atoi.o    ft_isdigit.o     ft_memcmp.o       ft_putchar.o    ft_strclr.o \
    ft_striter.o  ft_strncat.o  ft_strrchr.o    ft_bzero.o    ft_isprint.o \
    ft_memcpy.o   ft_putnbr.o   ft_strcmp.o   ft_striteri.o ft_strncmp.o \
    ft_strsplit.o    ft_isalnum.o  ft_memalloc.o ft_memdel.o   ft_putstr.o \
    ft_strcpy.o   ft_strlcat.o  ft_strncpy.o  ft_strstr.o ft_isalpha.o \
    ft_memccpy.o  ft_memmove.o  ft_strcat.o   ft_strdel.o   ft_strlen.o \
    ft_strnew.o   ft_tolower.o    ft_isascii.o  ft_memchr.o   ft_memset.o \
    ft_strchr.o   ft_strdup.o   ft_strmap.o   ft_strnstr.o  ft_toupper.o \
    ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_itoa.o \
    ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_putendl.o ft_lstmap.o \
	ft_lstadd.o ft_lstdel.o  ft_lstdelone.o ft_lstiter.o ft_strjoin.o \
	ft_strtrim.o ft_lstnew.o


all: $(NAME)

$(NAME): $(OBJ) $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): %.o : %.c
	gcc -Wall -Wextra -Werror -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
