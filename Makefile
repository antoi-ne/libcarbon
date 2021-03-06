# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 13:34:53 by ancoulon          #+#    #+#              #
#    Updated: 2021/03/04 20:40:30 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libcarbon.a

CC			= clang -g
AR			= ar rc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I./include

SRCS		= $(wildcard source/*/*.c)
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
