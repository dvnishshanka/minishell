#include "../../includes/minishell.h"

/*
echo "$PWD"
/home/dvnishshanka/minishell

echo '$PWD'
$PWD

echo Hello '$PWD'
Hello $PWD

echo "Hello '$PWD'"
Hello '/home/dvnishshanka/minishell'
*/
char	**expander(t_tools *tools, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i] != NULL)
	{
        // If the $PWD is inside single quotes it will not be interpreted.
        // If there's NULL terminator after $ it will not be interpreted.
        // dollar_sign return cannot be 0, it means there's no $ sign.
        // TODO: However, echo "Hello '$PWD'" in this instance it should be interpreted.
		if (str[i][dollar_sign(str[i]) - 2] != '\'' && dollar_sign(str[i]) != 0
			&& str[i][dollar_sign(str[i])] != '\0')
		{
			tmp = detect_dollar_sign(tools, str[i]);
			free(str[i]);
			str[i] = tmp;
		}
		if (ft_strncmp(str[0], "export", ft_strlen(str[0]) - 1) != 0)
		{
			str[i] = delete_quotes(str[i], '\"');
			str[i] = delete_quotes(str[i], '\'');
		}
		i++;
	}
	return (str);
}

/* If there is a digit after $ sign this will return 2. Else return 0.*/
static int	handle_digit_after_dollar(int j, char *str)
{
	if (str[j] == '$')
	{
		if (ft_isdigit(str[j + 1]) == 1)
		{
			return (2);
		}
	}
	return (0);
}

int	loop_if_dollar_sign(t_tools *tools, char *str, char **tmp, int j)
{
	int		k;
	int		ret;
	char	*tmp2;
	char	*tmp3;

	k = 0;
	ret = 0;
	while (tools->envp[k])
	{
		if (ft_strncmp(str + j + 1, tools->envp[k], equal_sign(tools->envp[k]) - 1) == 0
			&& after_dol_length(str, j) - j == (int)equal_sign(tools->envp[k]))
		{
            // Gives the value of the env variable
			tmp2 = ft_strdup(tools->envp[k] + equal_sign(tools->envp[k]));
			tmp3 = ft_strjoin(*tmp, tmp2);
			free(*tmp);
			*tmp = tmp3;
			free(tmp2);
			ret = equal_sign(tools->envp[k]);
		}
		k++;
	}
	if (ret == 0)
		ret = after_dol_length(str, j) - j;
	return (ret);
}

/*
This str input is having a $ sign.
If there is a digit after $, j will be incremented and move on.
    echo $8 hello
    hello
    echo $89
    9
*/
static char	*detect_dollar_sign(t_tools *tools, char *str)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = 0;
	tmp = ft_strdup("\0");
	while (str[j])
	{
		j += handle_digit_after_dollar(j, str);
        // Handles $?
		if (str[j] == '$' && str[j + 1] == '?')
			j += question_mark(&tmp);
        // Handles env variables
		else if (str[j] == '$' && (str[j + 1] != ' ' && (str[j + 1] != '"'
					|| str[j + 2] != '\0')) && str[j + 1] != '\0')
			j += loop_if_dollar_sign(tools, str, &tmp, j);
		else
		{
			tmp2 = char_to_str(str[j++]);
			tmp3 = ft_strjoin(tmp, tmp2);
			free(tmp);
			tmp = tmp3;
			free(tmp2);
		}
	}
	return (tmp);
}

