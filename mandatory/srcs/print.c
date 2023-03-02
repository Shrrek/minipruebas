/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:01:22 by jperales          #+#    #+#             */
/*   Updated: 2023/02/23 16:01:26 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_print_line(char *str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i] != ' ' && str[i] != '\0')
		{
			printf("%c", str[i]);
			i++;
		}
	}
}

void    ft_print2dstr(char **str)
{
	int i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			printf("%s\n", str[i]);
			i++;
		}
	}
}

void    ft_print2dstr_export(char **str)
{
	int i;
	int	j;

	i = 0;
	while (str[i])
	{
		printf("declare -x ");
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '=')
			{
				printf("%c", str[i][j]);
				j++;
				printf("\"");
			}
			printf("%c", str[i][j]);
			j++;
		}
		i++;
		printf("\"\n");
	}
}
