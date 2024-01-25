#ifndef MINISHELL_H
# define MINISHELL_H

// Libraries
# include "../libraries/libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# include "executor.h"
# include "error.h"
# include "parser.h"
# include "utils.h"

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

// `g_global` is a global variable
t_global	g_global;

// Prototypes
#endif
