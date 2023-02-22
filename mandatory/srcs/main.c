/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:49:33 by sperez-p          #+#    #+#             */
/*   Updated: 2023/02/22 19:30:09 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**ft_create_newenv(char **env, char *new_var, t_mini *minishell)
{
	char	**new_env;
	size_t	env_len;
	int	i;
	int	j;

	i = -1;
	env_len = ft_2dstrlen((const char **)env);
	new_env = (char **)malloc(sizeof(char *) * ((int)env_len + 2));
	if (!new_env)
		ft_process_error(MALLOC_ERROR, minishell);
	while (env[++i])
	{
		j = -1;
		new_env[i] = (char *)malloc(sizeof(char) * ft_strlen(env[i]) + 1);
		if (!new_env)
			ft_process_error(MALLOC_ERROR, minishell);
		while (env[i][++j])
			new_env[i][j] = env[i][j];
		new_env[i][j] = '\0';
	}
	j = -1;
	new_env[i] = (char *)malloc(sizeof(char) * ft_strlen(new_var) + 1);
	if (!new_env[i])
		ft_process_error(MALLOC_ERROR, minishell);
	while (new_var[++j])
		new_env[i][j] = new_var[j];
	return (new_env);
}

char	**ft_export_variable(char **env, char *new_var, t_mini *minishell)
{
	int	i;
	size_t	var_len;
	char 	**new_env;

	i = -1;
	var_len = ft_strchr(new_var, '=');
	while (env[++i])
	{
		if (ft_strnstr(env[i], new_var, var_len + 1) >= 0)
		{
			env[i] = ft_strdup(new_var, minishell);
			return (env);
		}
	}
	new_env = ft_create_newenv(env, new_var, minishell);
	return (new_env);
}

int main(int argc, char **argv, char **envp)
{
	t_mini	minishell;
	char	**new_env;
	int		i;

	i = 0;
	(void)argc;
	(void)argv;
	/*printf("\n\nANTES DE COPIAR\n\n");
	ft_print2dstr(envp);
	
	printf("\n\nDESPUES DE COPIAR\n\n");
	minishell.minienv = ft_2dstrdup((const char **)envp, &minishell);
	ft_print2dstr(minishell.minienv);
	
	printf("\n\nDESPUES DE QUINO\n\n");
	char	**prueba = envp;
	ft_print2dstr(prueba);*/
	
	printf("\n\nANTES DE HACER MOVIDAS - envp\n\n");
	ft_print2dstr(envp);
	new_env = ft_export_variable(envp, "USER=PRUEBA", &minishell);
	printf("\n\nDESPUES DE MODIFICAR UNA VARIABLE - new_env\n\n");
	ft_print2dstr(new_env);
	char **new_env1 = ft_export_variable(new_env, "VAR2=PRUEBA2", &minishell);
	printf("\n\nDESPUES DE CREAR UNA VARIABLE - new_env1\n\n");
	ft_print2dstr(new_env1);
	return (0);
}