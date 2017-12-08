#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yandriie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 08:48:11 by yandriie          #+#    #+#              #
#    Updated: 2017/11/23 14:17:13 by yandriie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = main.c ft_isvalid.c ft_istchr.c ft_newmat.c ft_delbuf.c ft_putdata.c ft_delmat.c ft_fillit.c ft_newbuf.c ft_mapbuf.c ft_fillres.c ft_printres.c

OBJ = $(SRC:.c=.o)

LIB = libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	cd ./libft && make && mv $(LIB) ..
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $<

clean:
	/bin/rm -f $(OBJ)
	cd ./libft && make clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIB)
	/bin/rm -f ./libft/$(LIB)

re: fclean all