# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 19:38:29 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/27 23:16:19 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a 
SRCS		= ft_bzero.c ft_calloc.c \
				ft_isdigit.c ft_itoa.c ft_strdup.c ft_strlcpy.c \
				ft_memset.c ft_strlen.c  \
				ft_printf_csdi.c ft_printf_hex.c ft_printf_pointer.c \
				ft_printf_unsigned.c ft_printf.c

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
OBJS		= $(SRCS:%.c=%.o)

all:		$(NAME)
$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
%.o : %.c
			$(CC) $(CFLAGS) -c $?
		
clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re