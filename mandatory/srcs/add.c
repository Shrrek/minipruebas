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
	size_t i;
	size_t j;
	size_t start;

	i = 0;
	j = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			if (str[i] == 34)
			{
				i++;
				while (str[i])
				{
					i++;
					if (str[i] == 34)
					{
						dest[j++] = ft_splitdup(str, start, i + 1);
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
						dest[j++] = ft_splitdup(str, start, i + 1);
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
				if (str[i] == c || i == ft_strlen(str))
					dest[j++] = ft_splitdup(str, start, i);
			}
			while (str[i] == c && str[i])
			{
				i++;
				start = i;
			}			
		}
	}
	dest[j] = NULL;
	return (dest);
}

static size_t ft_line_counter(const char *str, char c)
{
	size_t count;

	count = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		if (*str == 34 || *str == 39)
		{
			if (*str == 34)
			{
				str++;
				while (*str && *str != 34)
					str++;
			}
			else
			{
				str++;
				while (*str && *str != 39)
					str++;
			}
			str++;
			count++;
		}
		else
		{
			while (*str && *str != c)
				str++;
			while (*str && *str == c)
				str++;
			count++;			
		}
	}
	return (count);
}

char **ft_split(const char *str, char c)
{
	char **dest;

	if (!str)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_line_counter(str, c) + 1));
	if (!dest)
		return (NULL);
	ft_process_string(dest, str, c);
	return (dest);
}