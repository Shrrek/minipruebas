#include "../incs/minishell.h"

/* 
 * Copia el contenido de str en una nueva cadena y libera el contenido de la anterior.
 * Esta pensada para cuando sustituimos el puntero de una cadena alojada en malloc por 
 * otra dirección de memoria.
 */
char	*ft_swap_str(char *str)
{
	//printf("\nSWAP STR\n");
	int i;
	char *dst;

	i = -1;
	if (!str)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen((const char *)str) + 1);
	if (!dst)
		return (NULL);
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	free(str);
	return (dst);
}

/*
 * Copia el contenido de str en una nueva cadena alojada con malloc().
 * Si se utiliza para reasignar un valor a una variable, hay que utilizar una funcion
 * que copie el contenido y libere el antiguo espacio de memoria despues.
 */
char	*ft_strdup(const char *str)
{
	//printf("\nSTRDUP\n");
	int i;
	char *dst;

	i = -1;
	if (!str)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen((const char *)str) + 1);
	if (!dst)
		return (NULL);
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}

/*
 * Copia n bytes del contenido de str en una nueva cadena alojada con malloc().
 * Si se utiliza para reasignar un valor a una variable, hay que utilizar una funcion
 * que copie el contenido y libere el antiguo espacio de memoria despues.
 */
char	*ft_strndup(const char *str, size_t n)
{
	//printf("\nSTRNDUP\n");
	char	*dst;
	size_t	len;

	len = ft_strlen(str);
	if (!str)
		return (NULL);
	if (n > len)
		n = len;
	dst = (char *)malloc(sizeof(char) * n + 1);
	if (!dst)
		return (NULL);
	dst[n] = '\0';
	while (n--)
		dst[n] = str[n];
	return (dst);
}

/*
 * Copia el contenido de str en una nueva cadena y libera el contenido de la anterior.
 * Esta pensada para cuando sustituimos el puntero de una cadena alojada en malloc por
 * otra dirección de memoria.
 */
char	**ft_swap_2dstr(char **str)
{
	//printf("\nSWAP 2DSTR\n");
	int i;
	char **dst;

	i = -1;
	if (!str)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_strlen((const char *)str) + 1));
	if (!dst)
		return (NULL);
	while (str[++i])
		dst[i] = ft_strdup(str[i]);
	dst[i] = NULL;
	ft_free_2dstr(str);
	return (dst);
}

/*
 * Copia el contenido de cada cadena de str en un nuevo array de cadenas, alojado con malloc().
 * Si se utiliza para reasignar un valor a una variable, hay que utilizar una funcion
 * que copie el contenido y libere el antiguo espacio de memoria despues.
 */
char **ft_2dstrdup(const char **str)
{
	//printf("\n2DSTRDUP\n");
	int i;
	char **dst;

	i = -1;
	if (!str)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * ((int)ft_2dstrlen(str) + 1));
	if (!dst)
		return (NULL);
	while (str[++i])
		dst[i] = ft_strdup(str[i]);
	dst[i] = NULL;
	return (dst);
}

/*
 * Copia n bytes del contenido de cada cadena de str en un nuevo array de cadenas, alojado con malloc().
 * Si se utiliza para reasignar un valor a una variable, hay que utilizar una funcion
 * que copie el contenido y libere el antiguo espacio de memoria despues.
 */
char **ft_2dstrndup(const char **str, size_t cols)
{
	//printf("\n2DSTRNDUP\n");
	int		i;
	char	**dst;

	i = -1;
	if (!str)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * ((int)ft_2dstrlen(str) + 1));
	if (!dst)
		return (NULL);
	while (str[++i])
		dst[i] = ft_strndup(str[i], cols);
	dst[i] = NULL;
	return (dst);
}

/*
 * Copia n cadenas str en un nuevo array de cadenas, alojado con malloc().
 * Si se utiliza para reasignar un valor a una variable, hay que utilizar una funcion
 * que copie el contenido y libere el antiguo espacio de memoria despues.
 */
char	**ft_2dnstrdup(const char **str, size_t rows)
{
	//printf("\n2DNSTRDUP\n");
	char 	**dst;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_2dstrlen(str);
	if (rows > len)
		rows = len;
	dst = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!dst)
		return (NULL);
	dst[rows] = NULL;
	while (rows--)
		dst[rows] = ft_strdup(str[rows]);
	return (dst);
}

/*
 * Copia cols bytes de rows cadenas de str en un nuevo array de cadenas, alojado con malloc().
 * Si se utiliza para reasignar un valor a una variable, hay que utilizar una funcion
 * que copie el contenido y libere el antiguo espacio de memoria despues.
 */
char	**ft_2dnstrndup(const char **str, size_t rows, size_t cols)
{
	//printf("\n2DNSTRNDUP\n");
	int i;
	char **dst;
	size_t len;

	i = -1;
	if (!str)
		return (NULL);
	len = ft_2dstrlen(str);
	if (rows > len)
		rows = len;
	dst = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!dst)
		return (NULL);
	dst[rows] = NULL;
	while (rows--)
		dst[rows] = ft_strndup(str[i], cols);
	return (dst);
}