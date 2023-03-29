/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:44:57 by jperales          #+#    #+#             */
/*   Updated: 2023/03/28 18:45:02 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"



// Devuelve el indice de la cadena mas pequeña dentro de un array

void	ft_print2dstr_export(char **str)
{
	int	i;
	int	j;
	int	*pos_lst;

	i = -1;
	pos_lst = ft_get_2dstr_order((const char **)str);
	while (str[++i])
	{
		printf("declare -x ");
		j = -1;
		while (str[pos_lst[i]][++j])
		{
			if (str[pos_lst[i]][j] == '=')
			{
				printf("%c", str[pos_lst[i]][j]);
				j++;
			}
			printf("%c", str[pos_lst[i]][j]);
		}
		printf("\n");
	}
}

char	*ft_strdup_free(const char *str, char *src)
{
	int		i;
	char	*dst;

	i = -1;
	if (!str)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen((const char *)str) + 1);
	if (!dst)
		return (NULL);
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	free(src);
	return (dst);
}

char	**ft_create_newenv(char **env, char *new_var)
{
	char	**new_env;
	size_t	env_len;
	int		i;

	i = -1;
	env_len = ft_2dstrlen((const char **)env) + 2;
	new_env = (char **)malloc(sizeof(char *) * env_len);
	if (!new_env)
		return (NULL);
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = ft_strdup(new_var);
	new_env[++i] = NULL;
	ft_free_2dstr(env);
	return (new_env);
}

/*int	ft_search_string(char *str1, char *str2, int n)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] == str2[i] && str1[i] && str2[i] && n--)
	{
		if (n == 0)
			return (1);
		i++;
	}
	return (0);
}*/

int	ft_export_var(t_mini *minishell, char **input_split, int j, int i)
{
	char	**env_var_split;

	env_var_split = ft_split(minishell->mini_env[j], '=');
	if (ft_str_equals(input_split[0], env_var_split[0]))
	{
		if (input_split[1])
			minishell->mini_env[j] = ft_strdup_free(minishell->next_line_split[i], minishell->mini_env[j]);
		ft_free_2dstr(env_var_split);
		ft_free_2dstr(input_split);
		return (1);
	}
	ft_free_2dstr(env_var_split);
	return (0);
}

void	ft_export(t_mini *minishell)
{
	char	**input_split;
	int		i;
	int		j;

	i = 0;
	if (ft_2dstrlen((const char **)minishell->next_line_split) == 1)
		ft_print2dstr_export(minishell->mini_env);
	else
	{
		while (minishell->next_line_split[++i])
		{
			j = -1;
			input_split = ft_split(minishell->next_line_split[i], '=');
			while (minishell->mini_env[++j])
			{
				if (ft_export_var(minishell, input_split, j, i))
					break ;
			}
			if (minishell->mini_env[j] == NULL )
				minishell->mini_env = ft_create_newenv(minishell->mini_env, minishell->next_line_split[i]);
			//ft_free_2dstr(input_split);
		}		
	}
}
