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

void	parse_envp(t_tools *tools)
{
    char *path_from_envp;
    int i;
    char *tmp;

    // Find the PATH environment variable from tools->envp
    path_from_envp = find_path(*tools);

    // Split the PATH into individual paths using ':' as the delimiter
    tools->paths = ft_split(path_from_envp, ':');
    free(path_from_envp);

    i = 0;
    // Ensure each path ends with a trailing slash
    while (tools->paths[i])
    {
        if (ft_strncmp(&tools->paths[i][ft_strlen(tools->paths[i]) - 1], "/", 1) != 0)
        {
            // If the last character is not '/', concatenate a '/' to the path
            tmp = ft_strjoin(tools->paths[i], "/");
            free(tools->paths[i]);
            tools->paths[i] = tmp;
        }
        i++;
    }
}