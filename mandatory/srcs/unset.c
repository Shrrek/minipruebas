/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:59:46 by jperales          #+#    #+#             */
/*   Updated: 2023/03/24 16:59:50 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_unset(t_mini *minishell)
{
	int		i;
	size_t	var_len;
	char	*var;

	i = 0;
	var = ft_join_chr(minishell->next_line_split[1], '=');
	var_len = ft_strlen(var);
	while (minishell->mini_env[i])
	{
		if (ft_strnstr(minishell->mini_env[i], var, var_len))
		{
			while (minishell->mini_env[i])
			{
				minishell->mini_env[i] = ft_strdup(minishell->mini_env[i + 1]);
				i++;
			}
			break ;
		}
		i++;
	}
}
