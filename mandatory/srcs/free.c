#include "../incs/minishell.h"

/*
 * Libera un array 2d
 */
void ft_free_2dstr(char **str)
{
	//printf("\nFREE 2DSTR\n");
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void ft_general_free(t_mini *minishell)
{
	if (minishell->mini_env)
		ft_free_2dstr(minishell->mini_env);
	if (minishell->next_line)
		free(minishell->next_line);
}
