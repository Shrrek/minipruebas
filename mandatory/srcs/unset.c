#include "../incs/minishell.h"

char	**ft_unset(t_mini *minishell)
{
	int i;
	size_t  var_len;
	char	*var;

	i = -1;
	var = ft_join_chr(minishell->next_line_split[1], '=');
	printf("nueva %s\n", var);
	var_len = ft_strlen(var);

	printf("variable %s y longitud %zu\n", var, var_len);
	while (minishell->mini_env[++i])
	{
		if (ft_strnstr(minishell->mini_env[i], var, var_len))
			printf("aqui encuentra\n");
	}
	return (minishell->mini_env);
}