/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:29:00 by jperales          #+#    #+#             */
/*   Updated: 2023/02/20 19:32:25 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	t_general   var;
	int	i;

	(void)argc;
	(void)argv;

	i = 0;
	while (env[i])
	{
		i++;
	}
	var.env = malloc(sizeof(char **));
	i = 0;
	while (env[i])
	{
		var.env[i] = env[i];
		printf("%s \n", var.env[i]);
		i++;
	}
	return (0);
}