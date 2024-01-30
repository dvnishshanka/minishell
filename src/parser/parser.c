#include "../../includes/minishell.h"

/* Here the 'str' will contain commands until the end or till it encounter a PIPE*/
static	t_simple_cmds	*initialize_cmd(t_parser_tools *parser_tools)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	
	rm_redirections(parser_tools);
	arg_size = count_args(parser_tools->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		parser_error(1, parser_tools->tools, parser_tools->lexer_list);
	tmp = parser_tools->lexer_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i] = ft_strdup(tmp->str);
			i++;
			ft_lexerdelone(&parser_tools->lexer_list, tmp->i);
			tmp = parser_tools->lexer_list;
		}
		arg_size--;
	}
	return (ft_simple_cmdsnew(str, parser_tools->num_redirections, parser_tools->redirections));
}

/* There cannot be pipe in adjacent lexer_list tokens
After removing the lexer_list_node with PIPE, lexer_list cannot be NULL
 */
int	handle_pipe_errors(t_tools *tools, t_tokens token)
{
	if (token == PIPE)
	{
		parser_double_token_error(tools, tools->lexer_list,
			tools->lexer_list->token);
		return (1);
	}
	if (!tools->lexer_list)
	{
		parser_error(0, tools, tools->lexer_list);
		return (1);
	}
	return (0);
}

/*
If the lexer_list first node, token value is a PIPE it will throw a parser_double_token_error
*/
int	parser(t_tools *tools)
{
	t_simple_cmds	*node;
	t_parser_tools	parser_tools;

	tools->simple_cmds = NULL;
	count_pipes(tools->lexer_list, tools);
	if (tools->lexer_list->token == PIPE)
		return (parser_double_token_error(tools, tools->lexer_list, tools->lexer_list->token));
	while (tools->lexer_list)
	{
		if (tools->lexer_list && tools->lexer_list->token == PIPE)
			ft_lexerdelone(&tools->lexer_list, tools->lexer_list->i);
		if (handle_pipe_errors(tools, tools->lexer_list->token))
			return (1);
		parser_tools = init_parser_tools(tools->lexer_list, tools);
		node = initialize_cmd(&parser_tools);
		if (!node)
			parser_error(0, tools, parser_tools.lexer_list);
		if (!tools->simple_cmds)
			tools->simple_cmds = node;
		else
			ft_simple_cmdsadd_back(&tools->simple_cmds, node);
		tools->lexer_list = parser_tools.lexer_list;
	}
	return (0);
}