# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 11:47:06 by tale-fau          #+#    #+#              #
#    Updated: 2021/11/08 16:28:43 by tale-fau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	        =		philo

SRCS_PATH		=		./srcs

SRCS            =	$(SRCS_PATH)/errors.c \
						$(SRCS_PATH)/ft_atoi.c \
						$(SRCS_PATH)/is_digit.c \
						$(SRCS_PATH)/main.c \
						$(SRCS_PATH)/parsing.c \
						$(SRCS_PATH)/starter.c \
						$(SRCS_PATH)/display.c \
						$(SRCS_PATH)/ft_putchar_fd.c \
						$(SRCS_PATH)/ft_putnbr_fd.c \
						$(SRCS_PATH)/ft_putstr_fd.c \
						$(SRCS_PATH)/time.c \
						$(SRCS_PATH)/ft_strncmp.c \
						$(SRCS_PATH)/death.c \
						$(SRCS_PATH)/utils.c 

INCLUDES_DIR     =       ./includes/

CC              =       gcc

OBJS            =       ${SRCS:.c=.o}

RM          =       rm -rf

FLAGS       =       -Wall -Wextra -Werror -pthread -g -fsanitize=address

.c.o:
					@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o ${<:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
						@${CC} ${FLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS}
						@echo "\033[1;37m"
						@echo "\nlibft.a has been created"
						@echo "philo has been created"
						@echo "\033[0;31m"
						@cat .login.txt
						@echo "\033[1;35m"
						@cat .train.txt
						@echo "\033[1;37m"
						@echo "\ntchou tchou ;) c'est parti pour Philosophers !! Embarquement immédiat :D"

clean:
						@${RM} ${OBJS} ${OBJS_B}
						@echo "\033[1;37m"
						@echo "\n *.o files deleted\n"

fclean:		clean
						@${RM} ${NAME} ${NAME_B}
						@echo "\033[1;37m"
						@echo "\nPrograms The libft and philo have been deleted\n"

re:		fclean all

.PHONY:           all     clean   fclean  re
