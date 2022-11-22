# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 21:51:21 by donghyk2          #+#    #+#              #
#    Updated: 2022/11/22 16:18:02 by donghyk2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_printf.c forms.c func.c func2.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	libftprintf.a

HEADER		=	ft_printf.h

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

%.o :	%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY :	all clean fclean re
