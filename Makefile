# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 11:26:50 by arashido          #+#    #+#              #
#    Updated: 2023/08/17 15:07:39 by arashido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = array_methods.c error.c free_functions.c parsing.c utils.c \
	  operation_p.c operation_r.c operation_rr.c operation_s.c \
	  push_swap_atoi.c push_swap_libft.c radix.c sort_small_stack_norm.c sort_small_stack.c \

OBJ = $(addprefix obj/, $(SRC:.c=.o)) obj/push_swap.o

LIBFT_PATH = libs/libft
PRINTF_PATH = libs/printf

all: obj $(NAME)

obj/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(PRINTF_PATH)
	@make bonus -C ${LIBFT_PATH}
	$(CC) $(OBJ) -o $(NAME) $(LIBFT_PATH)/libft.a $(PRINTF_PATH)/ft_printf.a

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re obj bonus