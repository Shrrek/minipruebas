#include "../incs/minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	dest = malloc((ft_strlen(s1) + (ft_strlen(s2))) * sizeof(char) + 1);
	if (!dest)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char    **ft_change_env(t_mini *minishell, char *str, char *var)
{
	int i;
	size_t  var_len;

	i = -1;
	var_len = ft_strchr(str, '=');
	while (minishell->mini_env[++i])
	{
		if (ft_strnstr(minishell->mini_env[i], str, var_len + 1))
			minishell->mini_env[i] = ft_strjoin(str, var);
	}
	return (minishell->mini_env);
}

void	ft_cd(t_mini *minishell)
{
	char    *path;

	minishell->mini_path = NULL;
	minishell->mini_oldpath = NULL;
//	minishell->mini_path = getcwd(minishell->minipath, ft_strlen(minishell->minipath));
	minishell->mini_path = getcwd(minishell->mini_path, 1000);
//	printf("la ruta antes de cambiar era: %s\n", minishell->mini_path);
	minishell->mini_oldpath = ft_strdup(minishell->mini_path);
	path =  &minishell->next_line[ft_strchr(minishell->next_line, ' ') + 1];
	if (ft_strstr(path, "cd"))
	{
	//	printf("Vamos al HOME\n");
		chdir(minishell->mini_home);
	//	printf("la ruta es %s\n", minishell->mini_home);
		minishell->mini_env = ft_change_env(minishell, "PWD=", minishell->mini_home);
	}
	else
	{
		if (chdir(path) == -1)
		{
			printf("No such file or directory\n");
			return;
		}
		else
		{
			minishell->mini_path = getcwd(minishell->mini_path, 1000);
	//		printf("la pwd es: %s\n", minishell->mini_path);
			minishell->mini_env = ft_change_env(minishell, "PWD=", minishell->mini_path);
		}
	}
	//printf("la oldpwd es : %s\n", minishell->mini_oldpath);
	minishell->mini_env = ft_change_env(minishell, "OLDPWD=", minishell->mini_oldpath);
}
