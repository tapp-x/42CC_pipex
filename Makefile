# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 19:34:19 by tappourc          #+#    #+#              #
#    Updated: 2024/01/28 10:20:15 by tappourc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = \
	./src/main.c\
	./src/exec.c\
	./src/utils.c\

SRC_BONUS = \
		./bonus/main_bonus.c\
		./bonus/exec_bonus.c\
		./bonus/utils_bonus.c\
		./bonus/file_bonus.c\

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
CC = cc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = pipex
NAME_BONUS = pipex_bonus
LIBFT = libft-printf/
LIB-LIBFT = libftp.a
VG = valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes

%.o: %.c
	@echo "link" > link.txt
	@${CC} ${CFLAGS} -c $< -o $@

all : $(NAME)

$(NAME) : ${OBJ} clibft link

bonus : clibft ${OBJ_BONUS}
	@${CC} ${CFLAGS} ${OBJ_BONUS} ${LIBFT}${LIB-LIBFT} -o ${NAME}

link:
		@touch link.txt
		@if !(grep -x "link" link.txt > /dev/null); then \
			echo "Nothing to be done for All."; \
		else \
			${CC} ${CFLAGS} ${OBJ} ${LIBFT}${LIB-LIBFT} -o ${NAME};\
			echo "Compiling $(NAME) Done !"; \
		fi; \
		${RM} link.txt

clibft:
	@make -s -C ${LIBFT}

clean: cleanlibft
	@${RM} ${OBJ}
	@${RM} ${OBJ_BONUS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${NAME_BONUS}

cleanlibft:
	@cd ${LIBFT} && make clean > /dev/null
	@cd ${LIBFT}/libft && make clean > /dev/null

re: fclean all

.PHONY : all clean fclean re bonus
