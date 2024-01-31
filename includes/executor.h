#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

// executor.c
t_simple_cmds	*call_expander(t_tools *tools, t_simple_cmds *cmd);
#endif