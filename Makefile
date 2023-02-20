
NAME = minishell

LIB = libft/

CC = gcc

RM = rm -f

READLINE_DIR = ${HOME}/.brew/opt/readline

CFLAGS = -Wall -Werror -Wextra  #-g3 -fsanitize=address

F_READLINE = -l$(READLINE_DIR)/include

COMPILE = -lreadline -L$(READLINE_DIR)/lib

SRC = main.c\
	  

OBJS = $(SRC:.c=.o)

.c.o: $(SRC)
#	$(CC) $(CFLAGS) $(F_READLINE) -c -o $@ $<
	$(CC) $(CFLAGS) -c -o $@ $<
$(NAME): $(OBJS)
#	$(MAKE) -C $(LIB)
#	$(CC) $(CFLAGS) -o $(NAME) $(COMPILE) $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
all: $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS) $(LIB)*.o

fclean: clean
#	$(RM) $(NAME) $(LIB)libft.a
	$(RM) $(NAME)

.PHONY: all re clean fclean
