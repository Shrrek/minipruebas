#include "../incs/minishell.h"

char	*ft_delete_spaces(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	//printf("%s\n", str);
	while (str[++i])
	{
		if (str[i] == 34)
		{
			str[j] = str[i];
			j++;
			i++;
			while (str[i] && str[i] != 34)
			{
				str[j] = str[i];
				i++;
				j++;
			}
		}
		if (str[i] == 39)
		{
			str[j] = str[i];
			j++;
			i++;
			while (str[i] && str[i] != 39)
			{
				str[j] = str[i];
				i++;
				j++;
			}
		}
		while (str[i] == 32 && str[i + 1] == 32)
			i++;
		str[j] = str[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	*ft_find_del(char *str, int quote, int *i, int *j)
{
	if (str[*i] == quote)
	{
		++(*i);
		while (str[*i] && str[(*i)] != quote)
		{
			str[*j] = str[*i];
			(*j)++;
			(*i)++;
		}
	}
	return (str);
}

char 	*ft_delete_quotes(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		ft_find_del(str, 34, &i, &j);
		ft_find_del(str, 39, &i, &j);
		if (str[i] != 34 && str[i] != 39)
		{
			str[j]  = str[i];
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}

static int  ft_check_quote(const char *str, int quote, int *i)
{
    if (str[*i] == quote)
    {
        (*i)++;
        while (str[*i] && str[*i] != quote)
            (*i)++;
        if (str[*i])
            return (1);
        return (0);
    }
    return (1);
}

int ft_parse_quotes(const char *str)
{
    int     i;
    int		quote_34;
    int		quote_39;

    i = -1;
    quote_34 = 1;
    quote_39 = 1;
    while (str[++i])
    {
        quote_34 = ft_check_quote(str, 34, &i);
        quote_39 = ft_check_quote(str, 39, &i);
    }
    if (quote_34 == 1 && quote_39 == 1)
        return (1);
    return (0);
}