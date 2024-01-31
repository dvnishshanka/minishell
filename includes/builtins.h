#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

// builtins.c
int (*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd);
size_t	equal_sign(char *str);

// mini_echo.c
int	mini_echo(t_tools *tools, t_simple_cmds *simple_cmd);
#endif