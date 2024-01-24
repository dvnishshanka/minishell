#include "../../includes/minishell.h"

void	find_pwd(t_tools *tools)
{
    int i;

    i = 0;
    tools->pwd = NULL;
    tools->old_pwd = NULL;
    while (tools->envp[i])
    {
        if (ft_strncmp(tools->envp[i], "PWD=", 4) == 0)
            tools->pwd = &tools->envp[i][4];
        else if (ft_strncmp(tools->envp[i], "OLDPWD=", 7) == 0)
            tools->old_pwd = &tools->envp[i][7];     
        i ++;
    }
}
