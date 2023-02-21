
#include "minishell.h"

char	*ft_strdup(const char *str, t_mini *minishell)
{
	int		i;
	char	*dst;

	i = -1;
	if (!str)
		ft_error_exit(NULL_ERROR, minishell);
	dst = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dst)
		ft_error_exit(MALLOC_ERROR, minishell);
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}

char	**ft_2dstrdup(const char **str, t_mini *minishell)
{
	int		i;
	char	**dst;

	i = -1;
	if (!str)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * ((int)ft_2dstrlen + 1));
	if (!dst)
		ft_error_exit(MALLOC_ERROR, minishell);
	while (str[++i])
		dst[i] = ft_strdup(str[i], minishell);
	dst[i] = NULL;
	return (dst);
} 