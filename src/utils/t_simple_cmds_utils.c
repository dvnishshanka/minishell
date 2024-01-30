#include "../../includes/minishell.h"

void	ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new_node)
{
    t_simple_cmds   *current;

    if (!lst || !new_node)
        return ;
    if (!(*lst))
        *lst = new_node;
    else
    {
        current = (*lst);
        while (current->next)
            current = current->next;
        current->next = new_node;
        new_node->prev = current;
    }
}

/* This function creates a simple_cmd new node. */
t_simple_cmds   *ft_simple_cmdsnew(char **str, int num_redirections, t_lexer *redirections)
{
    t_simple_cmds   *new_element;

	new_element = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	if (!new_element)
		return (0);
    new_element->str = str;
    new_element->num_redirections = num_redirections;
    new_element->builtin = builtin_arr(str[0]);
    new_element->redirections = redirections;
    new_element->hd_file_name = NULL;
    new_element->prev = NULL;
    new_element->next = NULL;
    return (new_element);
}


// void	ft_simple_cmdsclear(t_simple_cmds **lst)
// {
// 	t_simple_cmds	*tmp;
// 	t_lexer			*redirections_tmp;

// 	if (!*lst)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		redirections_tmp = (*lst)->redirections;
// 		ft_lexerclear(&redirections_tmp);
// 		if ((*lst)->str)
// 			free_arr((*lst)->str);
// 		if ((*lst)->hd_file_name)
// 			free((*lst)->hd_file_name);
// 		free(*lst);
// 		*lst = tmp;
// 	}
// 	*lst = NULL;
// }