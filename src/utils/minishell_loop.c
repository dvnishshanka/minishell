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
    // init_signals();
}