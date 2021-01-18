# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 08:57:58 by pthomas           #+#    #+#              #
#    Updated: 2021/01/18 15:27:40 by pthomas          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#========================================#
#=============== VARIABLES ==============#
#========================================#

#~~~~ Sources ~~~~#

SRCS		=	ft_printf.c \
				ft_printf_utils.c \
				parser.c \
				params.c \
				params2.c \
				conv.c \
				conv2.c \

#~~~~ Objects ~~~~#

OBJS		= ${SRCS:.c=.o}
BOBJS		= ${BSRCS:.c=.o}

#~~~~ HEADERS ~~~~#

HEADERS		= ft_printf.h

#~~~~ Output ~~~~#

NAME		= libftprintf.a

#~~~~ Macros ~~~~#

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
RM			= rm -f

#========================================#
#=============== TARGETS ================#
#========================================#

#~~~~ Main Rules ~~~~#

all bonus:		${NAME}

$(NAME):	${OBJS}
			${MAKE} -C libft
			cp libft/libft.a ${NAME}
			${AR} ${ARFLAGS} ${NAME} $?

#~~~~ Compilation Rule ~~~~#

%.o : %.c	${HEADERS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I

#~~~~ Cleaning Rules ~~~~#
		
clean:
			${MAKE} clean -C libft
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${MAKE} fclean -C libft
			${RM} ${NAME}

#~~~~ Other Rules ~~~~#

re:			fclean all

.PHONY:		all bonus clean fclean re
