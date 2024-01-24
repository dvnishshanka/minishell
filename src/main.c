#include "../includes/minishell.h"

/*
The 'envp' parameter is a pointer to an array of strings, where each string represents an environment variable.
*/
int main(int argc, char **argv, char **envp)
{
    t_tools tools;
    int     i;

    i = 0;
    if (argc != 1 || argv[1])
        print_err("This program does not accept any inputs.\n");
    tools.envp = ft_arrdup(envp);
    while (tools.envp[i])
    {
        printf("%s\n", tools.envp[i]);
        i++;
    }
    find_pwd(&tools);
     printf("OLDPWD: %s\n", tools.old_pwd);
    printf("PWD: %s\n", tools.pwd);

    // printf("%s", readline("MINISHELL"));
    i = 0;
    //  while (envp[i])
    // {
    //     printf("%s\n", envp[i]);
    //     i++;
    // }
    // rl_clear_history();
    free_arr(tools.envp);
    return (0);
}