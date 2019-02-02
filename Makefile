# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 20:53:56 by ggrimes           #+#    #+#              #
#    Updated: 2019/02/02 15:42:23 by ggrimes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
LIB=./libft
FLAGS=-Wall -Wextra -Werror
FILES=fillit.c inscribe.c read_and_validate.c print.c \
	  process_map.c

all: ${NAME}

${NAME}:
			@make -C ${LIB} re
			gcc ${FLAGS} -I ${LIB} -L ${LIB} -lft -o ${NAME} ${FILES}

clean:
			make -C ${LIB} clean

fclean:	clean
			rm -f ${NAME}
			make -C ${LIB} fclean

re:	fclean all
