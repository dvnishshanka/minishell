#include "../../includes/minishell.h"

// Free an array of strings
void    free_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i ++;
    }
    free(arr);
}

// Returns a duplicate of an array of strings 
char	**ft_arrdup(char **arr)
{
    char    **rtn_str_arr;
    int     i;

    i = 0;
    while (arr[i])
        i ++;
    rtn_str_arr = (char **)ft_calloc(i + 1, sizeof (char *));
    if (!rtn_str_arr)
        print_err("Malloc Error");
    i = 0;
    while (arr[i])
    {
        rtn_str_arr[i] = (char *)ft_calloc(ft_strlen(arr[i]) + 1, sizeof (char));
        if (!rtn_str_arr[i])
        {
            free_arr(rtn_str_arr);
            print_err("Malloc Error");
        }
        ft_strlcpy(rtn_str_arr[i], arr[i], ft_strlen(arr[i]) + 1);
        i ++;
    }
    return (rtn_str_arr);
}
