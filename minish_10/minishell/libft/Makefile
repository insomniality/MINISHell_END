SRCS	=	$(shell find . -name "*.c")

OBJS	=	${SRCS:.c=.o}

NAME	=	libft.a
	
all: $(NAME)

$(NAME): ${OBJS}
	cc -Wall -Wextra -Werror -c $(SRCS)
	ar csr libft.a ${OBJS}

clean:
	rm -f ${OBJS} 

fclean:	clean
	rm -f $(NAME)

re:	fclean	all		

.PHONY:	all clean fclean re
