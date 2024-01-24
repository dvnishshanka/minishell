CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell
RM = rm -f

LIBFT = libft.a
LIBFT_DIR = libraries/libft
PATH_SRC = src
PATH_UTILS = src/utils
PATH_ERROR = src/error

SRCS =	$(PATH_SRC)/main.c	\
		$(PATH_UTILS)/utils.c	\
		$(PATH_UTILS)/parse_envp.c	\
		$(PATH_ERROR)/error.c
OBJS = $(SRCS:.c=.o)

# Compile source files into into object files
%.o: %.c $(INCLUDES_DIR)minishell.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -lreadline -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean