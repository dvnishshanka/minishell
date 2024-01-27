#include "../../includes/minishell.h"

void    init_tools(t_tools *tools)
{
    // *args;
    // tools->paths;
    tools->simple_cmds = NULL;
    tools->lexer_list = NULL;
	tools->pipes = 0;
	tools->pid = NULL;
	tools->heredoc = false;
	tools->reset = false;
    g_global.error_num = 0;
	g_global.stop_heredoc = 0;
	g_global.in_cmd = 0;
	g_global.in_heredoc = 0;
    parse_envp(tools);
    init_signals();
}

void	reset_tools(t_tools *tools)
{
	// ft_simple_cmdsclear(&tools->simple_cmds);
	free(tools->args);
	if (tools->pid)
		free(tools->pid);
	free_arr(tools->paths);
	init_tools(tools);
	tools->reset = true;
	minishell_loop(tools);
}

/*
If there's no input it will reset_tools and will give the prompt back.

History library introduce words from the history list into the input stream, 
making it easy to repeat commands, insert the arguments to a previous command into the current input line etc.
add_history function places a string at the end of the history list.
*/
void	minishell_loop(t_tools *tools)
{
	char	*tmp;

	tools->args = readline(READLINE_MSG);

	tmp = ft_strtrim(tools->args, " ");
	free(tools->args);
	tools->args = tmp;

    if (tools->args == NULL)
		print_err("Error in reading input.");
	if (tools->args[0] == '\0')
		return reset_tools(tools);
	add_history(tools->args);
    if (is_quotes_valid(tools->args) == false)
    {	
        ft_error(2, tools);
        return ;
    }
    token_reader(tools);
    t_lexer *node = tools->lexer_list;
    

    while (node)
    {
        printf("str: %s %d %d\n\n",node->str, node->token, node->i);
        node = node->next;
    }
	// if (!token_reader(tools))
	// 	return (ft_error(1, tools));
	// parser(tools);
	// prepare_executor(tools);
	reset_tools(tools);
}