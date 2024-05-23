# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 21:47:29 by ytsyrend          #+#    #+#              #
#    Updated: 2023/09/05 21:47:32 by ytsyrend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libftprintf.a
OBJ_DIR		=	obj
SRCS		=	ft_make_hexa.c \
			ft_printf.c\
			ft_printnmb.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strchr.c\
			ft_strlen.c\

OBJS     	=   $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
NAME		=	libftprintf.a
INCS		=	../headers/ft_printf.h
LIBC		=	ar rc
RM			=	rm -rf
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I../headers -fPIC

$(OBJ_DIR)/%.o: %.c ${INCS}
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean: 
	${RM} $(OBJ_DIR) main.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re
