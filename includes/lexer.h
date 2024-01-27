#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

void token_reader(t_tools *tools);
t_tokens	check_token(int c);
int	handle_quotes(int i, char *str, char del);
int	handle_token(char *str, int i, t_lexer **lexer_list);
int	add_node(char *str, t_tokens token, t_lexer **lexer_list);
#endif