#include "../../includes/minishell.h"

/*
This declaration states that builtin_arr is a function that takes a string as a parameter and
returns a pointer to a function that takes t_tools * and t_simple_cmds * as parameters and returns an integer.
*/
int (*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd)
{
	static void	*builtins[7][2] = {
	{"echo", mini_echo},
	// {"cd", mini_cd},
	// {"pwd", mini_pwd},
	// {"export", mini_export},
	// {"unset", mini_unset},
	// {"env", mini_env},
	// {"exit", mini_exit}
	};
	int			i;

    i = 0;
    while (i < 7)
	{
		if (str && ft_strncmp(str, builtins[i][0], ft_strlen(builtins[i][0])) == 0)
		{
			return (builtins[i][1]);
		}
		i ++;
	}
	return (NULL);
}

/*
If there is a equal sign in the string return the index after = sign , else return 0.
*/
size_t	equal_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}