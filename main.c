/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:29:00 by jperales          #+#    #+#             */
/*   Updated: 2023/02/20 19:55:00 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	t_general   var;
	int		i;
	char	*user;

	(void)argc;
	(void)argv;

	i = 0;
	while (env[i])
	{
		i++;
	}
	var.minienv = malloc(sizeof(char **));
	i = 0;
	while (env[i])
	{
		var.minienv[i] = env[i];
		printf("%s \n", var.minienv[i]);
		i++;
	}
	user = getenv("USER");
	printf("El usuario actual es: %s \n", user);
	return (0);
}