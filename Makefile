# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 11:26:50 by arashido          #+#    #+#              #
#    Updated: 2023/08/12 01:15:57 by arashido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = $(filter-out push_swap.c, $(wildcard *.c))

OBJ = $(addprefix obj/, $(SRC:.c=.o)) obj/push_swap.o

LIBFT_PATH = libs/libft

all: obj $(NAME)

obj/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@MAKE bonus -C ${LIBFT_PATH}
	$(CC) $(OBJ) -o $(NAME) $(LIBFT_PATH)/libft.a

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re obj bonus