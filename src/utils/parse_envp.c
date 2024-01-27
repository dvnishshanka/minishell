#include "../../includes/minishell.h"

/*
This function set the pwd and old_pwd values.
After using ft_substr, it needs to be freed.
*/
void	find_pwd(t_tools *tools)
{
    int i;

    i = 0;
    tools->pwd = NULL;
    tools->old_pwd = NULL;
    while (tools->envp[i])
    {
        if (ft_strncmp(tools->envp[i], "PWD=", 4) == 0)
            tools->pwd = ft_substr(tools->envp[i], 4, ft_strlen(tools->envp[i]) - 4);
        else if (ft_strncmp(tools->envp[i], "OLDPWD=", 7) == 0)
            tools->old_pwd = ft_substr(tools->envp[i], 7, ft_strlen(tools->envp[i]) - 7);    
        i ++;
    }
}

/*
Find and returns the PATH.
*/
char	*find_path(t_tools tools)
{
    int i;

    i = 0;
    while (tools.envp[i])
    {
        if (ft_strncmp(tools.envp[i], "PATH=", 5) == 0)
            return (ft_substr(tools.envp[i], 5, ft_strlen(tools.envp[i]) - 5));  
        i ++;
    }
    return (ft_strdup(""));
}

/*
The `PATH` environment variable contains a colon-separated list of directories.
Each directory in the list represents a location where the system looks for executable files.
'Executable' refers to a file that contains machine code or a script that is interpreted by a specific runtime environment.
Executables are files that can be run or executed by a computer's operating system to perform a specific task or set of tasks.
*/
// This function ensures that each path ends with a trailing slash
void	parse_envp(t_tools *tools)
{
    char *path_from_envp;
    int i;
    char *tmp;

    path_from_envp = find_path(*tools);
    tools->paths = ft_split(path_from_envp, ':');
    free(path_from_envp);
    i = 0;
    while (tools->paths[i])
    {
        if (ft_strncmp(&tools->paths[i][ft_strlen(tools->paths[i]) - 1], "/", 1) != 0)
        {
            tmp = ft_strjoin(tools->paths[i], "/");
            free(tools->paths[i]);
            tools->paths[i] = tmp;
        }
        i++;
    }
}