/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:01:08 by jperales          #+#    #+#             */
/*   Updated: 2023/02/23 18:34:05 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**ft_create_newenv(char **env, char *new_var, t_mini *minishell)
{
	char	**new_env;
	size_t	env_len;
	int	i;

	i = -1;
	env_len = ft_2dstrlen((const char **)env) + 2;
	new_env = (char **)malloc(sizeof(char *) * env_len);
	if (!new_env)
		ft_process_error(MALLOC_ERROR, minishell);
	while (env[++i])
		new_env[i] = ft_strdup(env[i], minishell);
	new_env[i] = ft_strdup(new_var, minishell);
	new_env[++i] = NULL;
	ft_free_2d_str(env);
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
			env[i] = ft_strdup_free(new_var, minishell, env[i]);
			return (env);
		}
	}
	new_env = ft_create_newenv(env, new_var, minishell);
	return (new_env);
}

int	ft_parse_34(t_mini *minishell)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (minishell->next_line[i])
	{
		if (minishell->next_line[i] = '34')
		{
			pos = i;
			while (minishell->next_line[++i] !='\0')
			{
				if (minishell->next_line[i] = '34')
				{
					return exito;
				}
				i++;
			}
			return fallo;
		}
		i++;
	}
	return fallo;
}

void	ft_process_next_line(t_mini *minishell)
{
	if (minishell->next_line == echo)
		jjkjsdjds
	else if(jbshhhufse)
		kjfkjsdhkj
	else if (hjdsagjhsd)
		jsdhh
	otrafuncion(shgajshdgasdhk)
	if (otrafuncion == -1 )
		pipie
}

int main(int argc, char **argv, char **envp)
{
	t_mini	minishell;
	
	(void)argc;
	(void)argv;
	
	//printf("\n\nDESPUES DE COPIAR\n\n");
	minishell.minienv = ft_2dstrdup((const char **)envp, &minishell);
	
	//printf("\n\nANTES DE HACER MOVIDAS - envp\n\n");
	minishell.minienv = ft_export_variable(minishell.minienv, "USER=PRUEBA", &minishell);
	printf("\n\nDESPUES DE MODIFICAR UNA VARIABLE - new_env\n\n");
	ft_print2dstr(minishell.minienv);
	
	//ft_print2dstr(envp);
	minishell.minienv = ft_export_variable(minishell.minienv, "VAR2=PRUEBA2", &minishell);
	printf("\n\nDESPUES DE CREAR UNA VARIABLE - new_env1\n\n");
	ft_print2dstr(minishell.minienv);
	while (1)
	{
		minishell.next_line = readline(">MiniTabaqueros ");
		ft_process_next_line();
		printf("linea = %s\n", minishell.next_line);
		free(minishell.next_line);
	}
	ft_free_2d_str(minishell.minienv);
	return (0);
}
