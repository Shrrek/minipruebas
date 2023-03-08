#include "../incs/minishell.h"

/*
 * Funcion que compara si dos cadenas son iguales
 */

int	ft_str_equals(const char *str1, const char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (!str1[i] && !str2[i])
		return (1);
	return (0);
}