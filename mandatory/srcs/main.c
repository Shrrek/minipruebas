/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:01:08 by jperales          #+#    #+#             */
/*   Updated: 2023/02/23 20:10:49 by jperales         ###   ########.fr       */
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

int	ft_parse_34_39(t_mini *minishell)
{
	int	i;
	int	count34;
	int	count39;

	count34 = 0;
	count39 = 0;
	i = 0;
	while (minishell->next_line[i])
	{
		if (minishell->next_line[i] == 34)
		{
			count34++;
		}
		i++;
	}
	i = 0;
	while (minishell->next_line[i])
	{
		if (minishell->next_line[i] == 39)
		{
			count39++;
		}
		i++;
	}
	if (count34 %2 == 0 || count39 %2 == 0)
		return (1);
	return (0);
}

void ft_no_quotes(char *str)
{
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if (str[i] != 34)
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

void	ft_process_next_line(t_mini *minishell)
{
	char	*dst;
	int		i;

	if(ft_parse_34_39(minishell))
	{
		if (ft_strstr(minishell->next_line, "echo"))
		{
			i = 4;
			if (minishell->next_line[i] != '\0')
			{
				ft_no_quotes(minishell->next_line);
				dst =  &minishell->next_line[ft_strchr(minishell->next_line, ' ') + 1];
				write (1, dst, ft_strlen(dst));
			}
			write (1, "\n", 1);
		}
		else if (ft_strstr(minishell->next_line, "env"))
		{
			i = 3;
			while (minishell->next_line[i] != '\0')
			{
				if (minishell->next_line[i] != ' ')
					ft_process_error(ENV_ERROR, minishell);
				i++;
			}
			ft_print2dstr(minishell->minienv);
		}
		else if (ft_strstr(minishell->next_line, "export"))
		{
			i = 6;
			minishell->minienv = ft_export_variable(minishell->minienv, &minishell->next_line[i + 1], minishell);
			ft_print2dstr_export(minishell->minienv);
		}
		
	}
	else 
		ft_process_error(ERROR_34, minishell);
/*	else if(jbshhhufse)
		kjfkjsdhkj
	else if (hjdsagjhsd)
		jsdhh
	otrafuncion(shgajshdgasdhk)
	if (otrafuncion == -1 )
		pipie*/
}

void	ft_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGQUIT)
	{
		NULL;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_mini	minishell;
	
	(void)argc;
	(void)argv;
	
	if (argc > 1)
		ft_process_error(ARGS_ERROR, &minishell);
	minishell.minienv = ft_2dstrdup((const char **)envp, &minishell);
	rl_catch_signals = 0;
	signal(SIGINT, ft_signal_handler);
	signal(SIGQUIT, ft_signal_handler);
	while (1)
	{
//		signal(SIGINT, ft_signal_handler);
//		signal(SIGQUIT, ft_signal_handler);
		minishell.next_line = readline(">MiniTabaqueros ");
		if (!minishell.next_line)
		{
			printf("exit\n");
			exit(0);
		}
		add_history(minishell.next_line);
		if (ft_strstr(minishell.next_line, "history -c"))
			rl_clear_history();
		ft_process_next_line(&minishell);
//		printf("linea = %s\n", minishell.next_line);
//		printf("\n%d\n", ft_parse_34(&minishell));
		free(minishell.next_line);
	}
	ft_free_2d_str(minishell.minienv);
	return (0);
}