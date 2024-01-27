#include "../../includes/minishell.h"

static bool ft_is_space(char c)
{
    return (c == ' ' || (c > 8 && c <= 13));
}

int skip_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i] && ft_is_space(str[i]))
        i ++;
    return (i);
}

int	add_node(char *str, t_tokens token, t_lexer **lexer_list)
{
	t_lexer	*node;

	node = ft_new_lexer(str, token);
	if (!node)
		return (0);
	ft_lexer_add_back(lexer_list, node);
	return (1);
}

static int	read_words(int i, char *str, t_lexer **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !(check_token(str[i + j])))
	{
		j += handle_quotes(i + j, str, '"');
		j += handle_quotes(i + j, str, '\'');
		if (ft_is_space(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, lexer_list))
		return (-1);
	return (j);
}

void token_reader(t_tools *tools)
{
    int i;
    int j;

    i = 0;
    while (tools->args[i])
    {
        j = 0;
        i += skip_spaces(&(tools->args[i]));
        if (check_token(tools->args[i]))
			j = handle_token(tools->args, i, &tools->lexer_list);
		else
			j = read_words(i, tools->args, &tools->lexer_list);
        if (j < 0)
            return ;
        i = i + j;
    }
}