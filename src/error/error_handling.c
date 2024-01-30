#include "../../includes/minishell.h"

void	parser_error(int error, t_tools *tools, t_lexer *lexer_list)
{
	ft_lexerclear(&lexer_list);
	ft_error(error, tools);
}

int	parser_double_token_error(t_tools *tools, t_lexer *lexer_list, t_tokens token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ",
		STDERR_FILENO);
	if (token == GREAT)
		ft_putstr_fd("'>'\n", STDERR_FILENO);
	else if (token == GREAT_GREAT)
		ft_putstr_fd("'>>'\n", STDERR_FILENO);
	else if (token == LESS)
		ft_putstr_fd("'<'\n", STDERR_FILENO);
	else if (token == LESS_LESS)
		ft_putstr_fd("'<<'\n", STDERR_FILENO);
	else if (token == PIPE)
		ft_putstr_fd("'|'\n", STDERR_FILENO);
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	ft_lexerclear(&lexer_list);
	reset_tools(tools);
	return (1);
}