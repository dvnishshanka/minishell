#include "../../includes/minishell.h"

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