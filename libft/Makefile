NAME=libft.a
FLAGS=-Wall -Wextra -Werror
LIBC_F=libc_fun/*.c
ADD_F=Additional_fun/*.c
BON_F=bonus/*.c
H=-Iincludes

all:	$(NAME)

$(NAME):
		@gcc $(FLAGS) $(H) -c $(LIBC_F) $(ADD_F) $(BON_F)
		@ar -urc $(NAME) *.o
		@ranlib $(NAME)

clean:
		@/bin/rm -fr *.o

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
