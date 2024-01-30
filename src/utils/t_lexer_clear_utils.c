#include "../../includes/minishell.h"

/*
Delete one node from the lexer_list
if clauses are used considering the situation that it can be the first node that is removed.
*/
void    ft_lexerdelone(t_lexer **lst, int   key)
{
    t_lexer *current;
    t_lexer *next_node;

    if (!lst || !(*lst))
        return ;
    current = *lst;
    while (current)
    {
        if (current->i == key)
        {
            if (current->prev)
                (current->prev)->next = current->next;
            if (current->next)
            (current->next)->prev = current->prev;
            if (current->str)
            {
                free(current->str);
                current->str = NULL;
            }
            next_node = current->next;
            if (*lst == current)
                *lst = next_node;
            free (current);
            break;
        }
        current = current->next;
    }
}

/*
Free the lexer_list
*/
void	ft_lexerclear(t_lexer **lst)
{
    t_lexer *lexer_next;

    if (!lst || !(*lst))
        return ;
    while (*lst)
    {
        lexer_next = (*lst)->next;
        if ((*lst)->str)
        {    
            free((*lst)->str);
            (*lst)->str = NULL;
        }
        free(*lst);
        *lst = lexer_next;  
    }
    *lst = NULL;
}