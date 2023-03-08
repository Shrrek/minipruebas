#include "../incs/minishell.h"
/*
 * Calcula la cantidad de caracteres que forman una cadena
 */
size_t ft_strlen(const char *str)
{
	//printf("\nSTRLEN\n");
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/*
 * Calcula la cantidad de cadenas que formar un array de cadenas
 */
size_t ft_2dstrlen(const char **str)
{
	//printf("\n2DSTRLEN\n");
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/*
 * Calcula la cantidad de caracteres que tienen cada cadena que forma un array de cadenas
 * Devuelve un array de size_ts con la longitud de cada cadena
 */
size_t *ft_2dstrstrlen(const char **str)
{
	//printf("\n2DSTRSTRLEN\n");
	size_t *lens;

	lens = (size_t *)malloc(sizeof(size_t) * ft_2dstrlen(str));
	if (!lens)
		return (NULL);
	int i = -1;
	while (str[++i])
		lens[i] = ft_strlen(str[i]);
	return (lens);
}

/*
 * Calcula la cantidad de veces que aparece un caracter en una cadena.
 */
int ft_get_chramt(const char *str, int c)
{
	//printf("\nGET CHRAMT\n");
	int i;
	int amt;

	i = -1;
	amt = 0;
	if (!str || c == '\0')
		return (0);
	while (str[++i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			amt++;
		}
	}
	return (amt);
}

/*
 * Devuelve el indice de la primera aparicion c dentro de la cadena
 */
int ft_get_chrlen(const char *str, int c)
{
	//printf("\nGET CHRLEN\n");
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == c)
		i++;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}