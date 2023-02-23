/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:01:32 by jperales          #+#    #+#             */
/*   Updated: 2023/02/23 16:01:35 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	ft_process_error(int type, t_mini *minishell)
{
	if (type == MALLOC_ERROR)
		printf("Error.\nFailed to allocate memory.\n");
	if (type == NULL_ERROR)
		printf("Error.\nNULL pointer.\n");
	ft_general_free(minishell);
	exit(-1);
}
