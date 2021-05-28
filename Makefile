# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 13:34:53 by ancoulon          #+#    #+#              #
#    Updated: 2021/05/28 13:54:29 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libcarbon.a

CC			= clang -g
AR			= ar rc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I./include

SRCS		= \
				source/fmt/fmt_fprint.c \
				source/fmt/fmt_fprintln.c \
				source/fmt/fmt_print.c \
				source/fmt/fmt_println.c \
				source/io/io_next_line.c \
				source/io/io_next_line_utils.c \
				source/llst/llst_destroy.c \
				source/llst/llst_destroyl.c \
				source/llst/llst_len.c \
				source/llst/llst_new.c \
				source/llst/llst_pop.c \
				source/llst/llst_push.c \
				source/llst/llst_shift.c \
				source/llst/llst_tail.c \
				source/llst/llst_unshift.c \
				source/mem/mem_calloc.c \
				source/mem/mem_cmp.c \
				source/mem/mem_cpy.c \
				source/mem/mem_set.c \
				source/mem/mem_setalloc.c \
				source/str/str_cat.c \
				source/str/str_cmp.c \
				source/str/str_cpy.c \
				source/str/str_dup.c \
				source/str/str_join.c \
				source/str/str_len.c \
				source/str/str_ncpy.c \
				source/str/str_ndup.c \
				source/str/str_split.c \
				source/str/str_sub.c \
				source/types/types_str2int.c \

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
