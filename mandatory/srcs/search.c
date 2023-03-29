/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:10:36 by jperales          #+#    #+#             */
/*   Updated: 2023/03/29 16:10:38 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle || !haystack)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i) && n)
	{
		j = 0;
		while (n-- && *(haystack + i + j) == *(needle + j))
		{
			if (*(needle + j++ + 1) == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

/*
 * Busca la primera aparicion de una subcadena en una cadena
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	if (!needle || !haystack)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[++i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
	}
	return (NULL);
}

/*
 * Busca la primera aparación de un caracter en una cadena y devuelve la posicion en la que se encuentra.
 * Si no encuentra el caracter devuelve -1.
 */
int	ft_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	//printf("cadena en strchr = %s\n", str);
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}
