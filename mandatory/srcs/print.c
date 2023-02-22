/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:51:22 by sperez-p          #+#    #+#             */
/*   Updated: 2023/02/22 19:27:48 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void    ft_print2dstr(char **str)
{
	int i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			printf("%s\n", str[i]);
			i++;
		}
	}
}