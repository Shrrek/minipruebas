#include "../incs/minishell.h"

/*
 * Añade un nuevo caracter a una cadena. Libera el contenido anterior
 */
char	*ft_join_chr(char *str, int c)
{
	//printf("\nJOIN CHR\n");
	char *new_str;
	int i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!new_str)
		return (NULL);
	if (str)
	{
		while (str[i])
		{
			new_str[i] = str[i];
			i++;
		}
		free(str);
	}
	new_str[i] = c;
	new_str[++i] = '\0';
	return (new_str);
}

/*
 * Mitico split del libft
 */
static char *ft_splitdup(const char *s, size_t start, size_t finish)
{
	//printf("\nJOIN CHR\n");
	char *dest;
	size_t i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

static char **ft_process_string(char **dest, const char *str, char c)
{
	printf("\nPROCESS STRING\n");
	size_t i;
	size_t j;
	size_t start;

	i = 0;
	j = -1;
	start = 0;
	//printf("str del split = %s\n", str);
	while (str[i])
	{
		//printf("ha entrado\n");
		/* Primero comprueba si empieza por comillas */
		if (str[i] == 34 || str[i] == 39)
		{
			/* Identifica que comilla ha encontrado*/
			if (str[i] == 34)
			{
				/* Ahora recorrremos la cadena hasta que encuentre la siguiente comilla y 
				el siguiente caracter a esta sea espacio o fin de cadena. Mientras no cumpla
				con ambas condiciones seguira recorriendo la cadena. Como anteriormente a esto ya hemos
				comprobado que  todas las comillas delimitantes tienen pareja, realmente no nos preocupa
				no encontrarla por que va a estar */
				while (str[++i])
				{
					/* Si encuentra su pareja de comillas toca examinar si su siguiente caracter es un espacio,
					un caracter nulo, o si sigue habiendo contenido */
					if (str[i] == 34)
					{
						while (str[i] != ' ' && str[i])
							i++;
						dest[++j] = ft_splitdup(str, start, i + 1);
						break;
					}
				}
			}
			else
			{
				i++;
				while (str[i])
				{
					i++;
					if (str[i] == 39)
					{
						dest[++j] = ft_splitdup(str, start, i + 1);
						break;
					}
				}
			}
			i++;
			start = i;
		}
		else
		{
			while (str[i] != c && str[i])
			{
				i++;
				if (str[i] == 34)
				{
					i++;
					while (str[i] && str[i] != 34)
						i++;
					if (str[i + 1] == c)
					{
						dest[++j] = ft_splitdup(str, start, i + 1);
						break;			
					}
					while (str[i] && str[i] != c)
						i++;
					dest[++j] = ft_splitdup(str, start, i);
				}
				else if (str[i] == 39)
				{
					i++;
					while (str[i] && str[i] != 39)
						i++;
					if (str[i + 1] == c)
					{
						dest[++j] = ft_splitdup(str, start, i + 1);
						break;			
					}
					while (str[i] && str[i] != c)
						i++;
					dest[++j] = ft_splitdup(str, start, i);
				}
				else if (str[i] == c || i == ft_strlen(str))
					dest[++j] = ft_splitdup(str, start, i);
				
			}
			while (str[i] == c && str[i])
			{
				i++;
				start = i;
			}			
		}
	}
	dest[++j] = NULL;
	//printf("%s\n", dest[j]);
	return (dest);
}

static void ft_split_quotes(const char **str, int *count, char c)
{
	//printf("\nSPLIT QUOTES\n");
	(*count)++;
	if (*(*str)== 34)
	{
		(*str)++;
			while (*(*str)&& *(*str)!= 34)
			(*str)++;
	}
	else
	{
		(*str)++;
		while (*(*str)&& *(*str)!= 39)
			(*str)++;
	}
	(*str)++;
	while (*(*str) && *(*str) != c)
		(*str)++;
}

static size_t ft_line_counter(const char *str, char c)
{
	//printf("\nLINE COUNTER\n");
	int count;

	count = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		if (*str == 34 || *str == 39)
			ft_split_quotes(&str, &count, c);
		else
		{
			while (*str && *str != c)
			{
				if (*str == 34)
				{
					str++;
					while (*str && *str != 34)
						str++;
				}
				else if (*str == 39)
				{
					str++;
					while (*str && *str != 39)
						str++;
				}
				str++;	
			}
			count++;
		}
		while (*str && *str == c)
			str++;
	}
	return (count);
}

char **ft_split(const char *str, char c)
{
	char **dest;

	if (!str)
		return (NULL);
	printf("cantidad de argumentos = %zu\n", ft_line_counter(str, c));
	dest = (char **)malloc(sizeof(char *) * (ft_line_counter(str, c) + 1));
	if (!dest)
		return (NULL);
	ft_process_string(dest, str, c);
	ft_print2dstr(dest);
	printf("\n");
	return (dest);
}