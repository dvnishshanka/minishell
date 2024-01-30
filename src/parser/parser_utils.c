#include "../../includes/minishell.h"

void    count_pipes(t_lexer *lexer_list,t_tools *tools)
{
    int pipe_count;

    pipe_count = 0;
    while (lexer_list)
    {
        if (lexer_list->token == PIPE)
            pipe_count ++;
        lexer_list = lexer_list->next;
    }
    tools->pipe_count = pipe_count;
}

/*
Initialize parser_tools
*/
t_parser_tools  init_parser_tools(t_lexer *lexer_list, t_tools *tools)
{
    t_parser_tools parser_tools;

    parser_tools.lexer_list = lexer_list;
    parser_tools.tools = tools;
    parser_tools.redirections = NULL;
    parser_tools.num_redirections = 0;
    return (parser_tools);
}

/*
Count the no of arguements in a command
*/
int	count_args(t_lexer *lexer_list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}