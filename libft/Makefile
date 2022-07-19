# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:19:15 by khovakim          #+#    #+#              #
#    Updated: 2022/07/08 15:15:37 by khovakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= $(wildcard ./*.c)
OBJS	= $(patsubst ./%.c, ./%.o, $(SRCS))
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I ../includes
AR		= ar -rcs
RM		= rm -f

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME)	: $(TMP) $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : re all fclean clean
