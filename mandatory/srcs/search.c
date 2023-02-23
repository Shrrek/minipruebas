/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:01:40 by jperales          #+#    #+#             */
/*   Updated: 2023/02/23 16:12:20 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/*
 * Busca la primera aparación de un caracter en una cadena y devuelve la posicion en la que se encuentra.
 * Si no encuentra el caracter devuelve -1.
 */
int ft_strchr(const char *str, int c)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

/*
 * Función que busca la primera aparición de una subcadena en una cadena, en un maximo de n bytes.
 * Si la encuentra devuelve el el caracter inicial donde se encuentra el primer caracter de la subcadena,
 * sino devuelve -1. Si la subcadena solo contiene un caracter nulo, la funcion devuelve -1.
 */

int ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t i;
	size_t j;

	i = -1;
	if (!str || !substr)
		return (-1);
	if (!*substr)
		return (-1);
	printf("\n%s y %s\n", &str[n], &substr[n]);
	while (str[++i] && n)
	{
		j = 0;
		while (n-- && str[i + j] == substr[j])
		{
			if (substr[j + 1] == '=')
				return (1);
			j++;
		}
	}
	return (-1);
}
