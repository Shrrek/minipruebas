#include "../incs/minishell.h"

void    ft_env(char **env)
{
    int i;

    i = -1;
    while (env[++i])
    {
        if(ft_strchr(env[i], '=') != -1)
            printf("%s\n", env[i]);
    }
}