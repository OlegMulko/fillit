# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 20:53:56 by ggrimes           #+#    #+#              #
#    Updated: 2019/01/31 22:13:31 by ggrimes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
INCLUDES=-I ./libft
FLAGS=-Wall -Wextra -Werror
LIB=-L ./libft -lft
FILES=fillit.c read_and_validate.c \
	  inscribe.c print.c

all: ${NAME}

${NAME}:
			gcc ${FLAGS} ${INCLUDES} ${LIB} -o ${NAME} ${FILES}

clean:
			rm -f ./libft/*.o

fclean:	clean
			rm -f ${NAME}

re:	fclean all
