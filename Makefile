CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell
RM = rm -f

LIBFT = libft.a
LIBFT_DIR = libraries/libft
INCLUDES_DIR = includes/
PATH_SRC = src
PATH_UTILS = src/utils
PATH_ERROR = src/error
PATH_LEXER = src/lexer
PATH_PARSER = src/parser
PATH_BUILTINS = src/builtins
PATH_EXECUTOR = src/executor

SRCS =	$(PATH_SRC)/main.c	\
		$(PATH_SRC)/signals.c	\
		$(PATH_UTILS)/utils.c	\
		$(PATH_UTILS)/parse_envp.c	\
		$(PATH_UTILS)/minishell_loop.c	\
		$(PATH_UTILS)/t_lexer_utils.c	\
		$(PATH_UTILS)/t_lexer_clear_utils.c	\
		$(PATH_UTILS)/t_simple_cmds_utils.c	\
		$(PATH_ERROR)/error.c	\
		$(PATH_ERROR)/error_handling.c	\
		$(PATH_LEXER)/token_reader.c	\
		$(PATH_LEXER)/handle_token.c	\
		$(PATH_LEXER)/handle_quotes.c	\
		$(PATH_PARSER)/parser.c	\
		$(PATH_PARSER)/parser_utils.c	\
		$(PATH_PARSER)/handle_redirections.c	\
		$(PATH_BUILTINS)/builtins.c	\
		$(PATH_BUILTINS)/mini_echo.c	\
		$(PATH_EXECUTOR)/handle_cmd.c	\
		$(PATH_EXECUTOR)/executor.c
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