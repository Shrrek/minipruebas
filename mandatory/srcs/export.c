/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:44:57 by jperales          #+#    #+#             */
/*   Updated: 2023/03/28 18:45:02 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"


void ft_print_nbrlst(int *nbr_lst, size_t lst_len)
{
	int i;

	i = -1;
	while (lst_len--)
		printf("%d\n", nbr_lst[++i]);
}

// Comprueba si un numero esta en un array de numeros
int ft_isin_intarr(int nbr, int *nbr_lst, size_t lst_len)
{
	while (lst_len--)
	{
		if (nbr == nbr_lst[lst_len])
			return (1);
	}
	return (0);
}
int ft_get_smaller_stridx(const char **str, int *nbr_lst, size_t lst_len)
{
	int i;
	int j;
	int index;

	index = 0;
	// Setea index con el indice la primera cadena de la lista que no esta en la lista de numeros
	while (ft_isin_intarr(index, nbr_lst, lst_len) == 1)
		index++;
	// Se iguala i con index para que empiece a comparar con la siguiente cadena
	i = index;
	while (str[++i] != NULL)
	{
		j = 0;
		// Si el indice de la cadena que va a comparar ya esta en la lista de indices pasa al siguiente.
		if (ft_isin_intarr(i, nbr_lst, lst_len) == 1)
			continue;
		while (str[index][j] == str[i][j])
			j++;
		if (str[index][j] > str[i][j])
			index = i;
	}
	return (index);
}
/*
 *
 * Parámetros:
 * Return:
 */
int *ft_get_2dstr_order(const char **str)
{
	int *pos_lst;

	size_t len;


	len = ft_2dstrlen(str);
	pos_lst = (int *)malloc(sizeof(int) * (len));
	if (!pos_lst)
		return NULL;
	int		lst_len;
	lst_len = 0;
	while (len--)
	{
		pos_lst[lst_len] = ft_get_smaller_stridx(str, pos_lst, lst_len);
		lst_len++;
	}
	return pos_lst;
	//ft_print_nbrlst(pos_lst, lst_len);
}

// Devuelve el indice de la cadena mas pequeña dentro de un array

void ft_print2dstr_export(char **str)
{
	int i;
	int j;
	int	*pos_lst;

	i = -1;
	pos_lst = ft_get_2dstr_order((const char **)str);
	while (str[++i])
	{
		printf("declare -x ");
		j = -1;
		while (str[pos_lst[i]][++j])
		{
			if (str[pos_lst[i]][j] == '=')
			{
				printf("%c", str[pos_lst[i]][j]);
				j++;

			}
			printf("%c", str[pos_lst[i]][j]);
		}
		printf("\n");
	}
}

char	*ft_strdup_free(const char *str, char *src)
{
	int		i;
	char	*dst;

	i = -1;
	if (!str)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen((const char *)str) + 1);
	if (!dst)
		return (NULL);
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	free(src);
	return (dst);
}

char	**ft_create_newenv(char **env, char *new_var)
{
	char	**new_env;
	size_t	env_len;
	int	i;

	i = -1;
	env_len = ft_2dstrlen((const char **)env) + 2;
	new_env = (char **)malloc(sizeof(char *) * env_len);
	if (!new_env)
		return (NULL);
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = ft_strdup(new_var);
	new_env[++i] = NULL;
	ft_free_2dstr(env);
	return (new_env);
}

int	ft_search_string(char *str1, char *str2, int n)
{
	int	i;
	
	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] == str2[i] && str1[i] && str2[i] && n--)
	{
		if (n == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_export_var(t_mini *minishell, char **input_split, int j, int i)
{
	char	**env_var_split;

	env_var_split = ft_split(minishell->mini_env[j], '=');
	if (ft_str_equals(input_split[0], env_var_split[0]))
	{
		if (input_split[1])
			minishell->mini_env[j] = ft_strdup_free(minishell->next_line_split[i], minishell->mini_env[j]);
		ft_free_2dstr(env_var_split);
		ft_free_2dstr(input_split);
		return (1);
	}
	ft_free_2dstr(env_var_split);
	return (0);
}

void	ft_export(t_mini *minishell)
{
	char	**input_split;
	int		i;
	int		j;

	i = 0;
	if (ft_2dstrlen((const char **)minishell->next_line_split) == 1)
		ft_print2dstr_export(minishell->mini_env);
	else
	{
		while (minishell->next_line_split[++i])
		{
			j = -1;
			input_split = ft_split(minishell->next_line_split[i], '=');
			while (minishell->mini_env[++j])
			{
				if (ft_export_var(minishell, input_split, j, i))
					break ;				
			}
			if (minishell->mini_env[j] == NULL )
				minishell->mini_env = ft_create_newenv(minishell->mini_env, minishell->next_line_split[i]);
			 //ft_free_2dstr(input_split);
		}		
	}
}
