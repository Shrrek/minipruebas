/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:29:00 by jperales          #+#    #+#             */
/*   Updated: 2023/02/21 20:30:03 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_mini   minishell;
	int		i;

	(void)argc;
	(void)argv;

	i = 0;
	while (envp[i])
	{
		i++;
	}
	minishell.minienv = (char **)malloc(sizeof(char *) * 2);
	i = 0;
	printf("\n\nANTES DE COPIAR\n\n");
	ft_print2dstr(envp);
	
	printf("\n\nDESPUES DE COPIAR\n\n");
	minishell.minienv = ft_2dstrdup((const char **)envp, &minishell);
	ft_print2dstr(minishell.minienv);
	
	printf("\n\nDESPUES DE QUINO\n\n");
	char	**prueba = envp;
	ft_print2dstr(prueba);
	/*while (envp[i])
	{
		var.minienv[i] = envp[i];
		printf("%s \n", var.minienv[i]);
		i++;
	}
	var.miniuser = getenv("USER");
	var.minipath = getenv("PATH");
	var.minihome = getenv("HOME");
	printf("El usuario actual es: %s \n", var.miniuser);
	printf("La ruta actual es: %s \n", var.minipath);
	printf("El Home actual es: %s \n", var.minihome);*/
	return (0);
}