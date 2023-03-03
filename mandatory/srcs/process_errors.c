/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:01:32 by jperales          #+#    #+#             */
/*   Updated: 2023/02/23 20:15:13 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_process_error(int type, t_mini *minishell)
{
	if (type == MALLOC_ERROR)
		printf("Error.\nFailed to allocate memory.\n");
	if (type == NULL_ERROR)
		printf("Error.\nNULL pointer.\n");
	if (type == ERROR_34)
		printf("Error.\nDouble Quotes not exits.\n");
	if (type == ARGS_ERROR)
		printf("Error.\nNo arguments please.\n");
	if (type == ENV_ERROR)
		printf("No such file or directory\n");
	if (type == DIR_ERROR)
		printf("No existe el directorio\n");

	
	ft_general_free(minishell);
	exit(-1);
}
