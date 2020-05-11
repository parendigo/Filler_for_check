# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 20:31:59 by mlarraq           #+#    #+#              #
#    Updated: 2020/03/23 13:59:22 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlarraq.filler

SRC = fill_numbers.c \
	  okantovka.c \
	  placer.c \
	  main.c \

LIBFT_DIR = libft
LIBS = libft/libft.a

OBJ = $(SRC:.c=.o)

HEADERS = filler.h

all: $(NAME)

$(LIBS):
	make -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIBS)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIBS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
