/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:09:33 by sperez-p          #+#    #+#             */
/*   Updated: 2023/03/14 17:09:34 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static void	ft_process_quote(const char *str, int *i, char quote)
{
	(*i)++;
	while (str[*i] && str[*i] != quote)
		(*i)++;
	(*i)++;
}

static void	ft_process_spaces(const char *str, int *i, int *start, char c)
{
	while (str[*i] && str[*i] == c)
	{
		(*i)++;
		*start = *i;
	}
}

static char	**ft_process_string(char **dest, const char *str, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = -1;
	start = 0;
	while (str[i])
	{
		ft_process_spaces(str, &i, &start, c);
		if (str[i] && (str[i] == 34 || str[i] == 39))
			ft_process_quote(str, &i, str[i]);
		if (str[i] && str[i] != c)
		{
			while (str[i] && str[i] != c && str[i] != 34 && str[i] != 39)
				i++;
		}
		if (!str[i] || str[i] == c)
		{
			dest[++j] = ft_strndup(&str[start], i - start);
			start = i;
		}
	}
	dest[++j] = NULL;
	return (dest);
}

static size_t	ft_line_counter(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			while (str[i] && str[i] != c)
			{
				if (str[i] == 34 || str[i] == 39)
					ft_process_quote(str, &i, str[i]);
				while (str[i] && str[i] != c && str[i] != 34 && str[i] != 39)
					i++;
			}
		}
		if (!str[i] || str[i] == c)
			count++;
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	char	**dest;

	if (!str)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_line_counter(str, c) + 1));
	if (!dest)
		return (NULL);
	ft_process_string(dest, str, c);
	return (dest);
}