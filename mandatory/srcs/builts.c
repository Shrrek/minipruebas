/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:05:47 by jperales          #+#    #+#             */
/*   Updated: 2023/03/28 19:05:50 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	//printf("\nsubstr\n");
	size_t	new_len;
	char	*dst;

	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	str = str + start;
	new_len = ft_strlen (str);
	if (len > new_len)
		len = new_len;
	dst = ft_strndup(str, len);
	return (dst);
}

char	*ft_strtrim(const char *str, char const *set)
{
	//printf("\STRTRIM\n");
	size_t	end;

	if (!str || !set)
		return (NULL);
	while (*str != '\0' && ft_strchr(set, *str) != -1)
		str++;
	end = ft_strlen(str) - 1;
	while (end && ft_strchr(set, str[end]) != -1)
		end--;
	return (ft_substr(str, 0, end + 1));
}

static void	ft_process_quotes(t_mini *minishell)
{
	if (minishell->next_line_split && minishell->next_line_split[0])
	{
		if (minishell->next_line_split[0][0] == 34)
			minishell->next_line_split[0] = ft_strtrim(minishell->next_line_split[0], "\"");
		else if (minishell->next_line_split[0][0] == 39)
			minishell->next_line_split[0] = ft_strtrim(minishell->next_line_split[0], "\'");
	}
}

void	ft_builts(t_mini *minishell)
{
	ft_process_quotes(minishell);
	if (ft_str_equals(minishell->next_line_split[0], "env"))
	{
		if (minishell->next_line_split[1] == NULL)
			ft_env(minishell->mini_env);
		else
			printf("Env error. No puede ir con argumentos\n");
	}
	else if (ft_str_equals(minishell->next_line_split[0], "echo"))
		ft_echo(minishell->next_line_split);
	else if (ft_str_equals(minishell->next_line_split[0], "pwd"))
		printf("%s\n", getcwd(minishell->mini_path, 1000));
	else if (ft_str_equals(minishell->next_line_split[0], "cd"))
		ft_cd(minishell);
	else if (ft_str_equals(minishell->next_line_split[0], "unset"))
		ft_unset(minishell);
	else if (ft_str_equals(minishell->next_line_split[0], "export"))
		ft_export(minishell);
}
