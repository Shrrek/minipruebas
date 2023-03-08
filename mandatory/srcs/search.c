#include "../incs/minishell.h"

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
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

