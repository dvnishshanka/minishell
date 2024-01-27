#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

// Prototypes
void    free_arr(char **arr);
char	**ft_arrdup(char **arr);
void    init_tools(t_tools *tools);
void	parse_envp(t_tools *tools);
void	minishell_loop(t_tools *tools);
bool     is_quotes_valid(char *args);
void	reset_tools(t_tools *tools);
t_lexer *ft_new_lexer(char *str, t_tokens token);
void    ft_lexer_add_back(t_lexer **lexer_list, t_lexer	*node);
#endif