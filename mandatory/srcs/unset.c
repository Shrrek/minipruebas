#include "../incs/minishell.h"

char	**ft_unset(t_mini *minishell)
{
	int i;
	int	j;
	size_t  var_len;
	char	*var;
	char	**dst;

	i = 0;
	j = 0;
	dst = NULL;
	var = ft_join_chr(minishell->next_line_split[1], '=');
	printf("nueva %s\n", var);
	var_len = ft_strlen(var);

	printf("variable %s y longitud %zu\n", var, var_len);
	while (minishell->mini_env[i])
	{
		dst[j] = (char *)malloc(sizeof(char) * ft_strlen(minishell->mini_env[i]));
		if (ft_strnstr(minishell->mini_env[i], var, var_len))
		{
			printf("aqui encuentra en la fila %d.\n", i);
			printf("cadena %s\n", minishell->mini_env[i]);
			i++;
		}
		dst[j] = ft_strdup(minishell->mini_env[i]);
		i++;
		j++;
	}
	return (dst);
}