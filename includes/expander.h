#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

// expander.c

// expander_utils.c
size_t	dollar_sign(char *str);
int	handle_question_mark(char **tmp);
#endif