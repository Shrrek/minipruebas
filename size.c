#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t  ft_2dstrlen(char **str)
{
	size_t  i;

	i = 0;
	if (str)
	{
		while(str[i])
			i++;
		return (i);
	}
	return (0);
}