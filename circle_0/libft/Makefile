# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 16:20:15 by donghyk2          #+#    #+#              #
#    Updated: 2022/11/14 16:39:57 by donghyk2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc

CFLAGS      = -Wall -Wextra -Werror

NAME        = libft.a

SRCS        = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS       = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
              ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS= $(SRCS:.c=.o)

OBJS_BONUS= $(BONUS:.c=.o)

HEADER= libft.h

ifdef BONUS_ON
    REALOBJS = $(OBJS) $(OBJS_BONUS)
else
    REALOBJS = $(OBJS)
endif

all : $(NAME)
	sleep 1

$(NAME) : $(REALOBJS)
	ar -rcs $@ $(REALOBJS)

bonus :
	make BONUS_ON=1

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : make fclean
	 make all

.PHONY: all re fclean clean bonus
