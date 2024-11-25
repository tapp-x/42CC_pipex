# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:17:05 by tappourc          #+#    #+#              #
#    Updated: 2024/01/26 09:38:53 by tappourc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_putchar.c \
	ft_printf.c \
	ft_putnbr_unsigned.c \
	ft_putnbr.c \
	ft_putstr.c \
	print_hex.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \

OBJ = ${SRC:.c=.o}
CC = gcc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftp.a
LIBFT = ./libft

all: ${NAME}

%.o: %.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
