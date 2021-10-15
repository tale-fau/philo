# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 11:47:06 by tale-fau          #+#    #+#              #
#    Updated: 2021/10/15 14:37:43 by tale-fau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	        =		philo

SRCS_PATH		=		./srcs

SRCS_NAME		=		main.c errors.c is_digit.c parsing.c ft_atoi.c starter.c

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
						$(SRCS_PATH)/ft_strncmp.c

INCLUDES_DIR     =       ./includes/

CC              =       gcc

OBJS            =       ${SRCS:.c=.o}

RM          =       rm -rf

FLAGS       =       -Wall -Wextra -Werror

.c.o:
					@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o ${<:.c=.o}
					@echo "\x1b[32m[LOADED]\033[0m ${<:.s=.o}"

all:			${NAME}

${NAME}:		${OBJS}
						@${CC} ${FLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS}
						@echo "\nlibft.a has been created"
						@echo "philo has been created"

clean:
						@${RM} ${OBJS} ${OBJS_B}
						@echo "\n *.o files deleted\n"

fclean:		clean
						@${RM} ${NAME} ${NAME_B}
						@echo "\nPrograms The libft and philo have been deleted\n"

re:		fclean all

.PHONY:           all     clean   fclean  re
