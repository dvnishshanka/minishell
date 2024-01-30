#include "../../includes/minishell.h"

/*
with -n flag it will not print a newline at the end.
*/
int	mini_echo(t_tools *tools, t_simple_cmds *simple_cmd)
{
    int		i;
	bool	n_option;

	i = 1;
	n_option = false;
	(void) tools;
	if (simple_cmd->str[i] && !ft_strncmp(simple_cmd->str[i], "-n", 3))
    {    
        n_option = true;
        i++;
    }
    while (simple_cmd->str[i])
	{    
        ft_putstr_fd(simple_cmd->str[i], STDOUT_FILENO);
        i++;
    }
	if (n_option == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
    return (0);
}