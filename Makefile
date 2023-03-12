S = srcs/
O = objs/
M = mandatory/

NAME = minishell

READLINE_DIR = ${HOME}/.brew/opt/readline
F_READLINE = -I$(READLINE_DIR)/include
COMPILE = -lreadline -L$(READLINE_DIR)/lib

SRCS = $M$Smain.c\
	   $M$Scopy.c\
	   $M$Sfree.c\
	   $M$Sprint.c\
	   $M$Serrors.c\
	   $M$Ssearch.c\
	   $M$Ssize.c\
	   $M$Sadd.c\
	   $M$Scompare.c\
	   $M$Sexport.c\
	   $M$Sparse.c\
	   $M$Ssignals.c\
   	   $M$Sbuilts.c\
	   $M$Secho.c\

OBJS = $M$Omain.o\
	   $M$Ocopy.o\
	   $M$Ofree.o\
	   $M$Oprint.o\
	   $M$Oerrors.o\
	   $M$Osearch.o\
	   $M$Osize.o\
	   $M$Oadd.o\
	   $M$Ocompare.o\
	   $M$Oexport.o\
	   $M$Oparse.o\
	   $M$Osignals.o\
  	   $M$Obuilts.o\
	   $M$Oecho.o\

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SANITIZE = -g3 -fsanitize=address

RM = -rm -rf

all: mandatory

mandatory: $(NAME)

$M$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $M$O

$(OBJS): $M$O%.o: $M$S%.c
	$(CC) $(CFLAGS) $(F_READLINE) -g3 -c $< -o $@

$(NAME): $(OBJS)
	@echo "Objects successfully created"
	@echo "Compiling mandatory...."
	$(CC) $(CFLAGS) $(SANITIZE) $(COMPILE) -g3 $^ -o $(NAME)
#	$(CC) $(CFLAGS) $(COMPILE) -g3 $^ -o $(NAME)
	@echo "Mandatory compiled"

clean:
	$(RM) $(OBJS) $M$O

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:  fclean clean all