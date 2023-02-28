/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:00:54 by jperales          #+#    #+#             */
/*   Updated: 2023/02/23 16:52:44 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_free_2d_str(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_general_free(t_mini *minishell)
{
	if (minishell->minienv)
		ft_free_2d_str(minishell->minienv);
	if (minishell->next_line)
		free(minishell->next_line);
}
