#include "../../includes/minishell.h"

/*
Create a new lexer node.
The 'static' keyword means that the variable retains its value between function calls.
Each time the ft_new_lexer function is called, the value of i is incremented and retained between calls.
*/
t_lexer *ft_new_lexer(char *str, t_tokens token)
{
    t_lexer *new_lexer;
    static int  i = 0;

    new_lexer = (t_lexer *)malloc(sizeof(t_lexer));
    if (!new_lexer)
        return (NULL);
    new_lexer->str = str;
    new_lexer->token = token;
    new_lexer->i = i++;
    new_lexer->next = NULL;
    new_lexer->prev = NULL;
    return (new_lexer);
}

/*
Returns the last node of the lexer_list.
*/
static t_lexer	*ft_lexerlast(t_lexer *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
Add a node to the end of the lexer_list
*/
void    ft_lexer_add_back(t_lexer **lexer_list, t_lexer	*node)
{
    t_lexer *last_lexer;

    if (!lexer_list || !node)
        return ;
    if (*lexer_list == NULL)
        *lexer_list = node;
    else
    {
        last_lexer = ft_lexerlast(*lexer_list);
        node->prev = last_lexer;
        last_lexer->next = node;
    }
}