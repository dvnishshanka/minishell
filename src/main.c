#include "../includes/minishell.h"

t_global	g_global;

/*
The 'envp' parameter is a pointer to an array of strings, where each string represents an environment variable.
*/
int main(int argc, char **argv, char **envp)
{
    t_tools tools;
    // int     i;

    // i = 0;
    if (argc != 1 || argv[1])
        print_err("This program does not accept any inputs.\n");
    tools.envp = ft_arrdup(envp);
    find_pwd(&tools);
    init_tools(&tools);
    // while (tools.envp[i])
    // {
    //     printf("%s\n", tools.envp[i]);
    //     i++;
    // }
    // printf("OLDPWD: %s\n", tools.old_pwd);
    // printf("PWD: %s\n", tools.pwd);
    // i = 0;
    // while (tools.paths[i])
    // {
    //     printf("%s\n", tools.paths[i]);
    //     i++;
    // }
    printf("-------------- Welcome to Minishell --------------\n");
    // printf("%s", readline("MINISHELL"));
    // i = 0;
    // rl_clear_history();
    // while(1)
    //     printf("H\n");
    minishell_loop(&tools);
    free_arr(tools.envp);
    free_arr(tools.paths);
    free(tools.old_pwd);
    free(tools.pwd);
    free(tools.args);
    return (0);
}