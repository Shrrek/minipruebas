/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:08:11 by jperales          #+#    #+#             */
/*   Updated: 2023/03/29 16:08:14 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
 * Printea un array 2d
 */
void	ft_print2dstr(char **str)
{
	//printf("\nPRINT\n");
	int	i;

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
