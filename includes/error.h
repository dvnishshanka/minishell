#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

// Prototypes
void    print_err(char *msg);
int	ft_error(int error, t_tools *tools);

// error_handling.c
int	parser_double_token_error(t_tools *tools, t_lexer *lexer_list, t_tokens token);
void	parser_error(int error, t_tools *tools, t_lexer *lexer_list);
#endif