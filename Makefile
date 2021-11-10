# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 23:25:00 by snuts             #+#    #+#              #
#    Updated: 2021/11/09 23:25:02 by snuts            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftprintf.a

SRCS	=	printf.c ft_ioa.c ft_putlen.c \
			ft_xXp.c

HEADER	=	ft_printf.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all