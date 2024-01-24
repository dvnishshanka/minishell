#include "../../includes/minishell.h"

void    print_err(char *msg)
{
    printf("%s\n", msg);
    exit(1);
}