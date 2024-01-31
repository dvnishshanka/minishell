#include "../../includes/minishell.h"

/* This function returns the index of the next char after finding '$' sign.*/
size_t	dollar_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

/*g_global.error_num the exit status of the last command*/
int	handle_question_mark(char **tmp)
{
	free(*tmp);
	*tmp = ft_itoa(g_global.error_num);
	return (2);
}

/*
Returns the index after performing several checks.
*/
int	after_dol_length(char *str, int j)
{
	int	i;

	i = j + 1;
	while (str[i] != '\0' && str[i] != '$' && str[i] != ' '
		&& str[i] != '\"' && str[i] != '\'' && str[i] != '=' && str[i] != '-'
		&& str[i] != ':')
		i++;
	return (i);
}