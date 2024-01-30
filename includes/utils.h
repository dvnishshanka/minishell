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

// t_lexer_utils.c
t_lexer *ft_new_lexer(char *str, t_tokens token);
void    ft_lexer_add_back(t_lexer **lexer_list, t_lexer	*node);

// t_lexer_clear_utils.c
void	ft_lexerclear(t_lexer **lst);
void    ft_lexerdelone(t_lexer **lst, int   key);

// t_simple_cmds_utils.c
void	ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new_node);
t_simple_cmds   *ft_simple_cmdsnew(char **str, int num_redirections, t_lexer *redirections);
#endif