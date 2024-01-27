#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/*
When explicitly assigned a '1' to the first enumerator (PIPE) and
left the subsequent enumerators to be automatically assigned values that increment by 1. 
*/
typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

/*
envp	: An array of strings representing the environment variables. 
pwd		: String representing the present working directory
old_pwd	: String representing the previous working directory
*/
typedef struct s_tools
{
	char					*args;
	char					**paths;
	char					**envp;
	struct  s_simple_cmds	*simple_cmds;
	t_lexer					*lexer_list;
	char					*pwd;
	char					*old_pwd;
	int						pipes;
	int						*pid;
	bool					heredoc;
	bool					reset;
}   t_tools;

typedef struct  s_simple_cmds
{
	char                    **str;
	int						(*builtin)(t_tools *, struct s_simple_cmds *);
	int						num_redirections;
	char					*hd_file_name;
	t_lexer					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}   t_simple_cmds;

// Prototypes
void	find_pwd(t_tools *tools);
#endif