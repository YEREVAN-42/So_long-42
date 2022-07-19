# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 18:16:14 by khovakim          #+#    #+#              #
#    Updated: 2022/07/19 13:58:20 by khovakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	=	So_long
NAME2	=	Bonus_So_long
SRCS	=	$(wildcard ./srcs/*.c)
OBJS	=	$(patsubst ./srcs/%.c, ./srcs/%.o, $(SRCS))
SRCS_B	=	$(wildcard ./bonus/*.c)
OBJS_B	=	$(patsubst ./bonus/%.c, ./bonus/%.o, $(SRCS_B))
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
INCLUDE	=	-I./includes
LINKER	=	-L./libft -lft
RM		=	rm -f

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -Imlx -c $< -o $@

all : $(NAME1) $(NAME2)

LIB :
	@$(MAKE) -C ./libft

$(NAME1) : LIB $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKER) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME1)

$(NAME2) : LIB $(OBJS_B)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKER) $(OBJS_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME2)

clean :
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME1) $(NAME2)

re : fclean all

.PHONY : all fclean clean re