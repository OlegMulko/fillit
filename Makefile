# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 20:53:56 by ggrimes           #+#    #+#              #
#    Updated: 2019/02/02 14:17:28 by rstracke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
INCLUDES= ./includes/libft
FLAGS=-Wall -Wextra -Werror
LIB= ./includes
FILES=./src

all: ${NAME}

${NAME}:
			@make -C ${INCLUDES} re
			gcc ${FLAGS} -I ${INCLUDES} -I ${LIB} -L ${INCLUDES} -lft -o ${NAME} ${FILES}/*.c

clean:
			make -C ${INCLUDES} clean

fclean:	clean
			rm -f ${NAME}
			make -C ${INCLUDES} fclean

re:	fclean all
