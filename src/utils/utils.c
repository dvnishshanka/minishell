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

/*
quote_count[0] represents no of single quotes.
quote_count[1] represents no of double quotes.
*/
static int  count_quotes(char *args)
{
    int quote_count;
    int i;

    quote_count = 0;
    i = 0;
    while (args[i])
    {
        if (args[i] == '"' || (args[i] == '\''))
            quote_count ++;
        i ++;
    }
    return (quote_count);
}

bool is_quotes_valid(char *args)
{
    int     i; 
    char    *sym;
    int     j;

    i = 0;
    j = 0;
    if (!args)
        return (true);
    if (count_quotes(args) == 0)
        return (true);
    sym = (char *)ft_calloc(count_quotes(args) + 1, sizeof (char));
    if (!sym)
        print_err("Calloc Error");
    while(*args)
    {
        if (*args == '"' || *args == '\'')
        {    
            sym[i++] = *args;
        }
        args ++;
    }
    i = 0;
    while (sym[i] && sym[j])
    {
        j = i + 1;
        while (sym[j])
        {
            if (sym[i] == sym[j])
            {    
                if (j == (int)ft_strlen(sym) - 1)
                {
                    free(sym);
                    return (true);
                }
                i = j + 1;
                break;
            }
            if (j == (int)ft_strlen(sym) - 1)
            {
                free(sym);  
                return (false);
            }
            j ++;
        }
    }
    free(sym);
    return (false);
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
        print_err("Calloc Error");
    i = 0;
    while (arr[i])
    {
        rtn_str_arr[i] = (char *)ft_calloc(ft_strlen(arr[i]) + 1, sizeof (char));
        if (!rtn_str_arr[i])
        {
            free_arr(rtn_str_arr);
            print_err("Calloc Error");
        }
        ft_strlcpy(rtn_str_arr[i], arr[i], ft_strlen(arr[i]) + 1);
        i ++;
    }
    return (rtn_str_arr);
}
