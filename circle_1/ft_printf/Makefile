# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 21:51:21 by donghyk2          #+#    #+#              #
#    Updated: 2022/11/15 21:58:06 by donghyk2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=

OBJS		=	$(SRCS:.c=.o)

NAME		=	ft_printf.a

HEADER		=	ft_printf.h

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

%.o :	%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

re : make fclean
	 make all

.PHONY :	all clean fclean re
