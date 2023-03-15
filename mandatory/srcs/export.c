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
				printf("\"");
			}
			printf("%c", str[pos_lst[i]][j]);
		}
		printf("\"\n");
	}
}

void	ft_export(t_mini *minishell)
{
	printf("EXPORT VARIABLE");

	// Conseguir longitud de next line
	size_t	nl_len = ft_2dstrlen((const char **)minishell->next_line_split);
	// Si la longitud es uno escribimos el env de forma especial
	if (nl_len == 1)
	{
		ft_print2dstr_export(minishell->mini_env);
	}
}
/*	int i;
	size_t var_len;
	char **new_env;

	i = -1;

	var_len = ft_strchr(minishell->next_line[1], '=');
	while (env[++i])
	{
		if (ft_strnstr(env[i], new_var, var_len + 1) >= 0)
		{
			env[i] = ft_strdup_free(new_var, minishell, env[i]);
			return (env);
		}
	}
	new_env = ft_create_newenv(env, new_var, minishell);
	return (new_env);
}*/