#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

// Prototypes
void    free_arr(char **arr);
char	**ft_arrdup(char **arr);
void    init_tools(t_tools *tools);
void	parse_envp(t_tools *tools);
#endif