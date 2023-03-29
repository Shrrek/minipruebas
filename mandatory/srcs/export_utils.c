/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:25:07 by jperales          #+#    #+#             */
/*   Updated: 2023/03/29 16:25:10 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/*void	ft_print_nbrlst(int *nbr_lst, size_t lst_len)
{
	int	i;

	i = -1;
	while (lst_len--)
		printf("%d\n", nbr_lst[++i]);
}*/

// Comprueba si un numero esta en un array de numeros
int	ft_isin_intarr(int nbr, int *nbr_lst, size_t lst_len)
{
	while (lst_len--)
	{
		if (nbr == nbr_lst[lst_len])
			return (1);
	}
	return (0);
}

int	ft_get_smaller_stridx(const char **str, int *nbr_lst, size_t lst_len)
{
	int	i;
	int	j;
	int	index;

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
			continue ;
		while (str[index][j] == str[i][j])
			j++;
		if (str[index][j] > str[i][j])
			index = i;
	}
	return (index);
}

int	*ft_get_2dstr_order(const char **str)
{
	int		*pos_lst;
	size_t	len;
	int		lst_len;

	lst_len = 0;
	len = ft_2dstrlen(str);
	pos_lst = (int *)malloc(sizeof(int) * (len));
	if (!pos_lst)
		return (NULL);
	while (len--)
	{
		pos_lst[lst_len] = ft_get_smaller_stridx(str, pos_lst, lst_len);
		lst_len++;
	}
	return (pos_lst);
	//ft_print_nbrlst(pos_lst, lst_len);
}
