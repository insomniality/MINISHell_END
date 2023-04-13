
# #SRCS	=	$(shell find . -maxdepth 1 -name "*.c")
# SRCS	=	$(shell find ./src -name "*.c")

# OBJS	=	${SRCS:.c=.o}

# NAME	=	minishell

# # CFLAGS	=	-Wall -Wextra -Werror

# all: libsl $(NAME)

# libsl:
# 	cd libft && make; cd ..

# $(NAME): ${OBJS}
# 	gcc -lreadline ${OBJS} -L ./libft -lft -o ${NAME}

# clean:
# 	rm -f ${OBJS}
# 	make clean -C libft
# fclean:	clean
# 	rm -f $(NAME)
# 	make fclean -C libft
# re:	fclean all

# .PHONY:	all clean fclean re libsl


#####################


# .PHONY: all clean bonus fclean re

# NAME = minishell

# LIBFT_DIR = ./libft

# LIBFT = $(LIBFT_DIR)/libft.a

# MAKE = make

# CLEAN = clean

# FCLEAN = fclean

# SRCS = $(shell find "." -name "*.c" ! -name "ft_lst*.c")
# # SRCS = $(shell find ./src -name "*.c")

# OBJ = $(SRCS:.c=.o)

# CC = gcc 

# #FLAG = -Wall -Werror -Wextra -g

# LDFlAGS = -L /Users/lib
# CPPFLAGS = -I /Users/include

# DEL = rm -rf

# all: $(NAME)

# $(NAME): $(OBJ)
# 	@cd $(LIBFT_DIR)
# 	@$(MAKE) && mv libft.a ../
# 	$(CC) $(FLAG) $(OBJ) -L. -lft -I $(LIBFT) -L/usr/include -lreadline -o $(NAME) $(LDFlAGS) $(CPPFLAGS)

# $(LIBFT):
# 	@cd $(LIBFT_DIR) && $(MAKE)

# clean:
# 	@$(DEL) $(OBJ) $(NAME)
# 	@mv libft.a libft
# 	@cd $(LIBFT_DIR) && $(MAKE) $(CLEAN)

# fclean: clean
# 	@$(DEL) $(OBJ) 
# 	@$(DEL) libft.a
# 	@cd $(LIBFT_DIR) && $(MAKE) $(FCLEAN)

# re: fclean all

.PHONY: all clean bonus fclean re

NAME = minishell

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR) libft.a

MAKE = make

CLEAN = clean

FCLEAN = fclean

SRCS = $(shell find "." -name "*.c" ! -name "ft_lst*.c")

OBJ = $(SRCS:.c=.o)

CC = gcc 

FLAG =  -g # -ggdb3 -fsanitize=address # -Wall -Werror -Wextra

LDFlAGS = -L /Users/michaelarzumanyan/lib
CPPFLAGS = -I /Users/michaelarzumanyan/include

DEL = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cd $(LIBFT_DIR) && $(MAKE) && mv libft.a ./../
	@$(CC) $(FLAG) $(OBJ) -L. -lft -I $(LIBFT) -L/usr/include -lreadline -o $(NAME) $(LDFlAGS) $(CPPFLAGS)

$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE)

clean:
	@$(DEL) $(OBJ) $(NAME)
	@mv libft.a libft
	@cd $(LIBFT_DIR) && $(MAKE) $(CLEAN)

fclean: clean
	@$(DEL) $(OBJ) 
	@$(DEL) libft.a
	@cd $(LIBFT_DIR) && $(MAKE) $(FCLEAN)

re: fclean all