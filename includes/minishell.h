#ifndef MINISHELL_H
# define MINISHELL_H

// Libraries
# include "../libraries/libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>

# include "executor.h"
# include "parser.h"
# include "error.h"
# include "utils.h"
# include "lexer.h"
# include "builtins.h"

# define READLINE_MSG	"$> "

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

// `g_global` is a global variable
extern  t_global	g_global;

// Prototypes
void    init_signals(void);
#endif
